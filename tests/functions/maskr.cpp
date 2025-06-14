#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Test for maskr " << argv[0] << "\n";
    if (maskr<uint8_t>(4) != 0b00001111){
        std::cout << "Scalar failure\n";
        return -1;
    }

    Array<uint8_t,1> mask = linspace<uint8_t>(0,8,9);
		Array<uint8_t,1> A = maskr<uint8_t>(mask);
		Array<uint8_t,1> Result = literal<uint8_t>(0b00000000,0b00000001,0b00000011,0b00000111,0b00001111,0b00011111,0b00111111,0b01111111,0b11111111);
		if (any(A!=Result)){
			std::cout << "Array failure\n";
			return -1;
		}

    std::cout << "Tests passed\n\n";

}
