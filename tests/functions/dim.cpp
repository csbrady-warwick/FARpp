#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 4
#define NY 4

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing dim " << argv[0] << "\n";
	if (softCompare(dim(2.0,1.0),1.0)) {
		std::cout << "False negative\n";
		std::cout << "Scalar failure\n";
		return -1;
	}

	if (!softCompare(dim(2.0,1.0),0.0)) {
		std::cout << "False positive\n";
		std::cout << "Scalar failure\n";
		return -1;
	}

	Array<double,2> A(NX,NY), B(NX,NY), C(NX,NY), RESULT(NX,NY);
	A=1.0;
	B(Range(1,NX/2),Range())=A(Range(1,NX/2),Range())*2;
	B(Range(NX/2+1,NX),Range())=-A(Range(NX/2+1,NX),Range())*2;
	C=dim(A,B);
	RESULT(Range(1,NX/2),Range())=0.0;
	RESULT(Range(NX/2+1,NX),Range())=3.0;

	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (softCompare(C(i,j),RESULT(i,j))) {
				std::cout << "Array failure\n";
				return -1;
			}
		}
	std::cout << "Tests passed\n\n";
}
