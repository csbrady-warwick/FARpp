#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

	std::cout << "Testing leadz " << argv[0] << "\n";
	if (leadz(uint8_t(0b00001111))!=4){
		std::cout << "Scalar failure. Some leading zeros\n";
		return -1;
	}
	if (leadz(uint8_t(0b10000000))!=0){
		std::cout << "Scalar failure. No leading zeros\n";
	}
	if (leadz(uint16_t(0))!=16){
		std::cout << "Scalar failure uint16_t\n";
	}

	Array<uint32_t,2> A(10,10);
	A=0;

	if (any(leadz(A)!=32)){
		std::cout << "Array failure with uint32_t\n";
	}

	std::cout << "Tests passed\n\n";
}
