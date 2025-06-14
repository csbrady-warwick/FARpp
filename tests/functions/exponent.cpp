#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

	std::cout << "Testing exponent " << argv[0] << "\n";
	if (exponent(double(127)) != 7) {
		std::cout << "Exponent double failure\n";
		return -1;
	}

	if (exponent(float(127)) != 7) {
		std::cout << "Unsigned float exponent failure\n";
		return -1;
	}

	if (exponent(float(128)) != 8) {
		std::cout << "Float exponent failure\n";
		return -1;
	}

	Array<double, 2> a(NX, NY);
	a=128;
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (exponent(a(i,j)) != 8) {
				std::cout << "Array failure\n";
				return -1;
			}
		}
	std::cout << "Tests passed\n\n";
}
