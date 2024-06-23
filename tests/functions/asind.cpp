#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main(){
	std::cout << "Testing asind\n";
  Array<double,2> A(NX,NY), B;
	A=1.0;
	B=asind(A);

	if (softCompare(asind(1.0),90.0)) {
		std::cout << "Scalar failure\n";
		return -1;
	}

	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (softCompare(B(i,j),90.0)) {
				std::cout << "Array failure\n";
				return -1;
			}
		}
	std::cout << "Tests passed\n\n";
}
