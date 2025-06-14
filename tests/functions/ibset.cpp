#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Test for ibset " << argv[0] << "\n";
    if (ibset(0,1) != 2){
        std::cout << "Scalar failure\n";
        return -1;
    }

    Array<int16_t,1> A(8);
    Array<int16_t,1> bit = linspace<int16_t>(0,7,8);
    A=0;
    A = ibset(A,bit);
    for (int i = 1; i <= 8; i++){
        if (A(i) != 1 << (i-1)){
            std::cout << "Array failure\n";
            return -1;
        }
    }

    std::cout << "Tests passed\n";

}
