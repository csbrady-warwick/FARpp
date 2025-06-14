#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

	std::cout << "Testing bit_size " << argv[0] << "\n";
	if (bit_size(1) != sizeof(int) * CHAR_BIT) {
		std::cout << "Int size failed";
		return -1;
	}
	if (bit_size(1.0) != sizeof(double) * CHAR_BIT) {
		std::cout << "Double size failed";
		return -1;
	}
	if (bit_size(int64_t(1)) != 64) {
		std::cout << "Int64_t size failed";
		return -1;
	}
	Array<float,2> a(NX,NY);
	if (bit_size(a) != sizeof(float)* CHAR_BIT) {
		std::cout << "Array size failed";
		return -1;
	}
	std::cout << "Tests passed\n\n";
}
