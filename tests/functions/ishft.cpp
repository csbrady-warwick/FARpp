#include <iostream>
#include "far.h"

#define NX 2
#define NY 2

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing ishft " << argv[0] << "\n";
    if (ishft(0b00001111,2)!=0b00111100){
        std::cout << "ishft scalar left shift failure\n";
        return -1;
    }

    if (ishft(0b00001100,-2)!=0b00000011){
        std::cout << "ishft scalar right shift failure\n";
        return -1;
    }

    if (ishft(uint8_t(0b11110000),2)!=uint8_t(0b11000000)){
        std::cout << "ishft scalar left shift off failure\n";
        return -1;
    }

    if (ishft(0b00001111,-2)!=0b00000011){
        std::cout << "ishft scalar right shift off failure\n";
        return -1;
    }

    Array<uint8_t,2> A(NX,NY);
    A=0b00001111;
    if (any(ishft(A,2)!=0b00111100)){
        std::cout << "ishft array left shift failure\n";
        return -1;
    }

    A=0b00001100;
    if (any(ishft(A,-2)!=0b00000011)){
        std::cout << "ishft array right shift failure\n";
        return -1;
    }    

    std::cout << "Test successful\n";
}
