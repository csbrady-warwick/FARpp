#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main(){
	std::cout << "Testing acospi\n";
  Array<double,2> A(NX,NY), B;
	A=0.0;
	B=acospi(A);

	if (softCompare(acospi(0.0),0.5)) {
		std::cout << "Scalar failure\n";
		return -1;
	}

	//Check array
	for (int j=1;j<=NY;++j) {
		for (int i=1;i<=NX;++i){
			if (softCompare(B(i,j),0.5)) {
				std::cout << "Array failure\n";
				return -1;
			}
		}
	}
	std::cout << "Tests passed\n\n";
}