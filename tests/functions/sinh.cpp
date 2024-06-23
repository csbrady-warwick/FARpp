#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 49.737131903094587576905960196617555373606569523402034897459059637

using namespace far;

int main(){
	std::cout << "Testing sinh\n";
  Array<double,2> A(NX,NY), B;
	A=4.6;
	B=sinh(A);

	if (softCompare(sinh(4.6),RESULT)) {
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
