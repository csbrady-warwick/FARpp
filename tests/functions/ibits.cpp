#include <iostream>
#include "far.h"

using namespace far;

int main(){

    std::cout << "Test for ibits\n";
    if (ibits(0b1111,0,2) != 3){
        std::cout << "Scalar failure\n";
        return -1;
    }

    if (ibits(0b1011,2,2) != 2){
        std::cout << "Scalar failure\n";
        return -1;
    }

    int16_t src = 0b1011;
    Array<int16_t,1> A(4);
    Array<int16_t,1> pos = literal<int16_t>(0,1,2,3);
    Array<int16_t,1> len = literal<int16_t>(1,1,1,1);
    A = ibits(src,pos,len);
    if (A(1) != 1 || A(2) != 1 || A(3) != 0 || A(4) != 1){
        std::cout << "Failure marching source\n";
        std::cout << "Array failure\n";
        return -1;
    }

    pos = literal<int16_t>(0,0,0,0);
    len = literal<int16_t>(1,2,3,4);
    A = ibits(src,pos,len);
    if (A(1) != 1 || A(2) != 3 || A(3) != 3 || A(4) != 11){
        std::cout << "Failure marching length\n";
        std::cout << "Array failure\n";
        return -1;
    }

    Array<int16_t,1> srcA = literal<int16_t>(0b0001,0b0010,0b0100,0b1000);
    A = ibits(srcA,0,4);
    if (A(1) != 1 || A(2) != 2 || A(3) != 4 || A(4) != 8){
        std::cout << "Failure array source\n";
        std::cout << "Array failure\n";
        return -1;
    }

    std::cout << "Tests passed\n";

}