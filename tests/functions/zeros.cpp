#include <iostream>
#include "far.h"

using namespace far;

int main(){

    std::cout << "Testing zeros\n";

    Array<int,1> A = zeros<int>(10);
    if (A.getSize()!=10){
        std::cout << "Failure size zeros 1\n";
        return -1;
    }

    if (any(A!=0)){
        std::cout << "Failure value zeros 1\n";
        return -1;
    }

    Array<int,2> B = zeros<int>(5,5);
    if (B.getSize()!=25){
        std::cout << "Failure size zeros total\n";
        return -1;
    }

    if (B.getRankSize(1)!=5){
        std::cout << "Failure size zeros dim 1\n";
        return -1;
    }

    if (B.getRankSize(2)!=5){
        std::cout << "Failure size zeros dim 2\n";
        return -1;
    }

    if (any(B!=0)){
        std::cout << "Failure value zeros 2\n";
        return -1;
    }

    std::cout << "All tests passed\n";

}