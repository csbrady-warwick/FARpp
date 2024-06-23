#include <iostream>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing not\n";

    uint8_t tval = 0b10101010;
    if (f_not(tval) != 0b01010101){
        std::cout << "Failure in scalar not\n";
        return -1;
    }

    Array<uint8_t,1> A = literal<uint8_t>(0,1,2,3,4,5,6,7);
    Array<uint8_t,1> notA = literal<uint8_t>(255,254,253,252,251,250,249,248);
    if (any(f_not(A) != notA)){
        std::cout << "Failure in array not\n";
        return -1;
    }
    std::cout << "All tests passed\n";
}