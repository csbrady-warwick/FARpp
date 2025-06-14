#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing mvbits " << argv[0] << "\n";

    uint8_t p1 = 0b00000000;
    uint8_t p2 = 0b00111100;

    mvbits(p2,2,4,p1,3);
    if (p1!=0b01111000){
        std::cout << "Failure moving scalar 1\n";
        return -1;
    }

    p1 = 0b00000000;
    p2 = 0b10101010;
    mvbits(p2,0,8,p1,0);
    if (p1!=0b10101010){
        std::cout << "Failure moving scalar 2\n";
        return -1;
    }

    Array<uint8_t,1> a(8);
    a=0;
    uint8_t b= 0b11111111;
    Array<uint8_t,1> c=linspace(1,8,8);
    mvbits(b,0,c,a,0);
    uint8_t src=1;
    for (int i=1;i<=8;i++){
        if (a(i)!=src){
            std::cout << "Failure moving array\n";
            return -1;
        }
        src<<=1;
        src|=1;
    }

    std::cout << "All tests passed\n";
}
