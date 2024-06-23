#include <iostream>
#include "far.h"

using namespace far;

int main(){

    std::cout << "Testing ones\n";

    Array<int,1> A = ones<int>(10);
    if (A.getSize()!=10){
        std::cout << "Failure size ones 1\n";
        return -1;
    }

    if (any(A!=1)){
        std::cout << "Failure value ones 1\n";
        return -1;
    }

    Array<int,2> B = ones<int>(5,5);
    if (B.getSize()!=25){
        std::cout << "Failure size ones total\n";
        return -1;
    }

    if (B.getRankSize(1)!=5){
        std::cout << "Failure size ones dim 1\n";
        return -1;
    }

    if (B.getRankSize(2)!=5){
        std::cout << "Failure size ones dim 2\n";
        return -1;
    }

    if (any(B!=1)){
        std::cout << "Failure value ones 2\n";
        return -1;
    }

    std::cout << "All tests passed\n";

}