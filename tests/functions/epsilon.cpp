#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

	std::cout << "Testing epsilon " << argv[0] << "\n";
	if (epsilon(double(0)) != std::numeric_limits<double>::epsilon) {
		std::cout << "Scalar failure\n";
		return -1;
	}

	Array<float, 2> a(NX, NY);
	if (epsilon(a) != std::numeric_limits<float>::epsilon) {
		std::cout << "Array failure\n";
		return -1;
	}
	std::cout << "Tests passed\n\n";
}
