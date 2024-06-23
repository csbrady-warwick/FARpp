#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 0.8813735870195430252326093249797923090281603282616354107532956086

using namespace far;

int main(){
	std::cout << "Testing asinh\n";
  Array<double,2> A(NX,NY), B;
	A=1;
	B=asinh(A);

	if (softCompare(asinh(1.0),RESULT)) {
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
