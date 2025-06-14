#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Test for maskl " << argv[0] << "\n";
    if (maskl<uint8_t>(4) != 0b11110000){
        std::cout << "Scalar failure\n";
        return -1;
    }

    Array<uint8_t,1> mask = linspace<uint8_t>(0,8,9);
		Array<uint8_t,1> A = maskl<uint8_t>(mask);
		Array<uint8_t,1> Result = literal<uint8_t>(0b00000000,0b10000000,0b11000000,0b11100000,0b11110000,0b11111000,0b11111100,0b11111110,0b11111111);
		if (any(A!=Result)){
			std::cout << "Array failure\n";
			return -1;
		}

    std::cout << "Tests passed\n\n";

}
