#include <iostream>
#include "far.h"

#define NX 2
#define NY 2

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    //Scalar tests without wraparound
    std::cout << "Testing ishftc " << argv[0] << "\n";
    if (ishftc(0b00001111,2)!=0b00111100){
        std::cout << "ishftc scalar left shift failure\n";
        return -1;
    }

    if (ishftc(0b00001100,-2)!=0b00000011){
        std::cout << "ishftc scalar right shift failure\n";
        return -1;
    }

    //Scalar tests with wraparound
    if (ishftc(uint8_t(0b11110000),2)!=uint8_t(0b11000011)){
        std::cout << "ishftc scalar left shift off failure\n";
        return -1;
    }

    if (ishftc(uint8_t(0b00001111),-2)!=0b11000011){
        std::cout << "ishftc scalar right shift off failure\n";
        return -1;
    }

    //Scalar tests with size and no wraparound
    if (ishftc(0b00000011,2,4)!=0b00001100){
        std::cout << "ishftc scalar left shift with size failure\n";
        return -1;
    }

    //Scalar tests with size and wraparound
    if (ishftc(0b00001100,2,4)!=0b00000011){
        std::cout << "ishftc scalar left shift with size failure on wraparound\n";
        return -1;
    }


    Array<uint8_t,2> A(NX,NY);
    A=0b00001111;
    if (any(ishftc(A,2)!=0b00111100)){
        std::cout << "ishftc array left shift failure\n";
        return -1;
    }

    A=0b00001111;
    if (any(ishftc(A,-2)!=0b11000011)){
        std::cout << "ishftc array right shift failure\n";
        return -1;
    }    

    std::cout << "Test successful\n";
}
