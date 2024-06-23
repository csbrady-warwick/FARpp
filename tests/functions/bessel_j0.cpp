#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 0.7651976865579665514497175261026632209092742897553252418615475491

using namespace far;

int main(){
	std::cout << "Testing bessel_j0\n";
  Array<double,2> A(NX,NY), B;
	A=1.0;
	B=bessel_j0(A);

	if (softCompare(bessel_j0(1.0),RESULT)) {
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
