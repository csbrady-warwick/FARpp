#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 0.9098473801286611066396234217634616792998536221090838795003200371

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing gamma " << argv[0] << "\n";
  	Array<double,2> A(NX,NY), B;
	A=1.234;
	B=f_gamma(A);

	if (softCompare(f_gamma(1.234),RESULT)) {
		std::cout << "Scalar failure\n";
		return -1;
	}

	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (softCompare(B(i,j),RESULT)) {
				std::cout << "Array failure\n";
				return -1;
			}
		}
	std::cout << "Tests passed\n\n";
}
