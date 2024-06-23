#include <iostream>
#include "far.h"

using namespace far;

int main(){

    std::cout << "Test for ibclr\n";
    if (ibclr(0b1111,1) != 0b1101){
        std::cout << "Scalar failure\n";
        return -1;
    }

    Array<int16_t,1> A(4);
    Array<int16_t,1> mask(4);
    A = 0b1111;
    mask = linspace<int16_t>(0,3,4);
    A=ibclr(A,mask);
    if (A(1) != 0b1110 || A(2) != 0b1101 || A(3) != 0b1011 || A(4) != 0b0111){
        std::cout << "Array failure\n";
        return -1;
    }

    std::cout << "Tests passed\n";

}