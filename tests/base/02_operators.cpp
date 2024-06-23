#include <iostream>
#include "far.h"
using namespace far;
#define NL 4
#define MAX_RANK 8

template<typename T, int Rank=1>
bool testMaths(size_t N=NL){
    size_t dims[Rank];
    std::cout << "Testing maths operators for rank " << Rank << " with size " << N << "\n";
    for (int i=0; i<Rank; i++){
        dims[i]=N;
    }
    Array<T,Rank> A(dims);
    A=3;
    if (any(A*2!=6)){
        std::cout << "Error in multiply at rank " << Rank << "\n";
        return false;
    }
    if (any(A+A!=6)){
        std::cout << "Error in add at rank " << Rank << "\n";
        return false;
    }
    if (any(A-A!=0)){
        std::cout << "Error in subtract at rank " << Rank << "\n";
        return false;
    }
    if (any(A/A!=1)){
        std::cout << "Error in divide at rank " << Rank << "\n";
        return false;
    }
		if (any(1+A!=4)){
			std::cout << "Error in add, literal LHS at rank " << Rank << "\n";
		}
    if constexpr(Rank<MAX_RANK){
        if (!testMaths<T,Rank+1>(N)){
            return false;
        }
    }
    return true;
}

template<int Rank=1>
bool testBool(size_t N=NL){
    size_t dims[Rank];
    std::cout << "Testing Boolean operators for rank " << Rank << " with size " << N << "\n";
    for (int i=0; i<Rank; i++){
        dims[i]=N;
    }
    dims[0]/=2;

    Array<bool,Rank> A(dims), B(dims);
    A=true;
    B=false;

    if (any(!A)){
        std::cout << "Error in ! at rank " << Rank << "\n";
        return false;
    }

    if (any(A && B)){
        std::cout << "Error in && at rank " << Rank << "\n";
        return false;
    }

    if (!all(A || B)){
        std::cout << "Error in || at rank " << Rank << "\n";
        return false;
    }

    if constexpr(Rank<MAX_RANK){
        if (!testBool<Rank+1>(N)){
            return false;
        }
    }
    return true;

}

int main(){

    std::cout << "Testing operators\n";

    if (!testMaths<int>()){
        std::cout << "Error in mathematical operator test\n";
        return -1;
    }
    std::cout << "Mathematical operators passed\n";

    if (!testBool()){
        std::cout << "Error in Boolean operator test\n";
        return -1;
    }
    std::cout << "Boolean operators passed\n";


    std::cout << "All tests passed\n\n";
}
