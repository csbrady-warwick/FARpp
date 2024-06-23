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
			std::cout << "This shows swapping edge cells as is often used in finite difference schemes. To prevent the prints from overlapping the second rank waits for 100ms before printing\n";
		}

    far::Array<int,2> a(far::Range(0,4),far::Range(0,4));
    if (rank==0){
        a=reshape(far::linspace(1, 25, 25),5,5);
    } else {
				a=-reshape(far::linspace(1,25,25),5,5);
    }

		//Copy left hand edge to right guard cells
    MPI_Sendrecv(far::makeCopyIn(a(far::Range(1,3),1)),3,MPI_INT,1-rank,0,far::makeCopyOut(a(far::Range(1,3),4)),3,MPI_INT,1-rank,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		//Copy right hand edge to left guard cells
		MPI_Sendrecv(far::makeCopyIn(a(far::Range(1,3),3)),3,MPI_INT,1-rank,0,far::makeCopyOut(a(far::Range(1,3),0)),3,MPI_INT,1-rank,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

		std::this_thread::sleep_for(std::chrono::milliseconds(rank*100));
    std::cout << far::gridPrint(a) << "\n\n";

    MPI_Finalize();

}
