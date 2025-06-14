#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 49.747183738839221158548093290949105315991963760065329480036093884

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing cosh " << argv[0] << "\n";
  Array<double,2> A(NX,NY), B;
	A=4.6;
	B=cosh(A);

	if (softCompare(cosh(4.6),RESULT)) {
		std::cout << "Scalar failure\n";
		return -1;
	}

	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (softCompare(B(i,j),RESULT)) {
				std::cout << B(i,j) << "\n";
				std::cout << "Array failure\n";
				return -1;
			}
		}
	std::cout << "Tests passed\n\n";
}
