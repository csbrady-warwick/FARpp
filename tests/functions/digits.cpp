#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main(){

	std::cout << "Testing digits\n";
	if (digits(int64_t(0)) != 63) {
		std::cout << "Int64 digits failure\n";
		return -1;
	}

	if (digits(uint32_t(0)) != 32) {
		std::cout << "Unsigned int32 digits failure\n";
		return -1;
	}

	if (digits(float(0)) != 24) {
		std::cout << "Float digits failure\n";
		return -1;
	}

	Array<int64_t, 2> a(NX, NY);
	if (digits(a) != 63) {
		std::cout << "Array digits failure\n";
		return -1;
	}
	std::cout << "Tests passed\n\n";
}
