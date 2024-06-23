#include <iostream>
#include "far.h"
using namespace far;
#define NL 4
#define MAX_RANK 15

template<typename T, int Rank>
bool test(size_t N=NL){
    size_t dims[Rank];
    std::cout << "Testing rank " << Rank << " with size " << N << "\n";
    for (int i=0; i<Rank; i++){
        dims[i]=N;
    }
    Array<T,Rank> A(dims);
    A=1;
    if (any(A*2!=2)){
        std::cout << "Error in create at rank " << Rank << "\n";
        return false;
    }
    if constexpr(Rank<MAX_RANK){
        if (!test<T,Rank+1>(N)){
            return false;
        }
    }
    return true;
}

int main(){

    std::cout << "Testing create\n";

    Array<int,1> A1(256);
    A1=1;
    if (any(A1*2!=2)){
        std::cout << "Error in create at rank 1\n";
        return -1;
    }

    Array<int,2> A2(16,16);
    A2=1;
    if (any(A2*2!=2)){
        std::cout << "Error in create at rank 2\n";
        return -1;
    }

    Array<int,3> A3(16,16,16);
    A3=1;
    if (any(A3*2!=2)){
        std::cout << "Error in create at rank 3\n";
        return -1;
    }

    std::cout << "Manual tests of ranks 1-3 passed. Automatic testing to rank " << MAX_RANK << "\n";

    if (!test<int,1>()){
        std::cout << "Error in test\n";
        return -1;
    }
    std::cout << "All tests passed\n\n";
}
