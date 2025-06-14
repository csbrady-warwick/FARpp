#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 0.9997979416121844543487026495245875535938684196986215668537570211

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing tanh " << argv[0] << "\n";
  Array<double,2> A(NX,NY), B;
	A=4.6;
	B=tanh(A);

	if (softCompare(tanh(4.6),RESULT)) {
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
