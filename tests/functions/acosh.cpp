#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 1.3169578969248167086250463473079684440269819714675164797684722569

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing acosh " << argv[0] << "\n";
  Array<double,2> A(NX,NY), B;
	A=2.0;
	B=acosh(A);

	if (softCompare(acosh(2.0),RESULT)) {
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
