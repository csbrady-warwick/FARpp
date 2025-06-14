#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 0.9191623964135658425873230926445964141427237662759653868574257558

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing erf " << argv[0] << "\n";
	Array<double,2> A(NX,NY), B;
	A=1.2345;
	B=erf(A);

	if (softCompare(erf(1.2345),RESULT)) {
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
