#include <iostream>
#include "far.h"
#include <mpi.h>
#include <chrono>
#include <thread>

int main(int argc, char **argv){

    MPI_Init(&argc, &argv);
    int nproc;
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    if (nproc !=2){
        std::cerr << "This demo only works on two ranks\n";
        MPI_Abort(MPI_COMM_WORLD,-1);
    }
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

		if (rank==0) {
			std::cout << "This demo copies the centre sections of an array to another array on another MPI rank. The top left element (0,0) is set to be the rank, so that you know which printed array is which. To allow both prints to not overlap the second rank waits 100ms before printing\n";
		}

    far::Array<int,2> a(far::Range(0,4),far::Range(0,4)), b(far::Range(0,4),far::Range(0,4));
    b=0;
    if (rank==0){
        a=reshape(far::linspace(1, 25, 25),5,5);
    } else {
        a=reshape(far::linspace(26, 50, 25),5,5);
    }

    MPI_Sendrecv(far::makeCopyIn(a(far::Range(1,3),far::Range(1,3))), 9, MPI_INT, 1-rank, 0, far::makeCopyOut(b(far::Range(1,3),far::Range(1,3))), 9, MPI_INT, 1-rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    b(0,0) = rank;

		std::this_thread::sleep_for(std::chrono::milliseconds(rank*100));
    std::cout << far::gridPrint(b) << "\n\n";

    MPI_Finalize();

}
