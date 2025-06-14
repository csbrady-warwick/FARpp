#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Test for ior " << argv[0] << "\n";
    if (ior(0b01,0b10) != 3){
        std::cout << "Scalar failure (no common bits)\n";
        return -1;
    }

    if (ior(0b01,0b11)!=3){
        std::cout << "Scalar failure (common bits)\n";
        return -1;
    }

    Array<int16_t,1> A=linspace<int16_t>(1,8,8);
    Array<int16_t,1> B=linspace<int16_t>(8,1,8);

    Array<int16_t,1> result = ior(A,B);
    for (int i = 1; i <= 8; i++){
        if (result(i) != (A(i)|B(i))){
            std::cout << "Array failure\n";
            return -1;
        }
    }

    std::cout << "Tests passed\n";

}
