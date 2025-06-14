#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing merge_bits " << argv[0] << "\n";

    if (merge_bits(uint8_t(0b11110000), uint8_t(0b00001111),uint8_t(0b11110000)) != 0b11111111) {
        std::cout << "scalar merge_bits test failed\n";
        return -1;
    }

    Array<uint8_t,1> A(8), B(8), mask(8), merged;

    A=0b11111111;
    B=0b00000000;
    for (int i=1;i<=8;i++) {
        mask(i) = 1<<(i-1);
    }
    merged = merge_bits(A,B,mask);
    for (int i=1;i<=8;i++) {
        if (merged(i) !=1<<(i-1)) {
            std::cout << "array merge_bits test failed\n";
            return -1;
        }
    }

    std::cout << "merge_bits test passed\n\n";

}
