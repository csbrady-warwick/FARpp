#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing cosd " << argv[0] << "\n";
  Array<double,2> A(NX,NY), B;
	A=0.5;
	B=sinpi(A);

	if (softCompare(sinpi(0.0),0.0)) {
		std::cout << "Scalar failure\n";
		return -1;
	}

	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (softCompare(B(i,j),1.0)) {
				std::cout << B(i,j) << "\n";
				std::cout << "Array failure\n";
				return -1;
			}
		}
	std::cout << "Tests passed\n\n";
}
