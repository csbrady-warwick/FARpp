#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 0.5493061443340548456976226184612628523237452789113747258673471668

using namespace far;

int main(){
	std::cout << "Testing atanh\n";
  Array<double,2> A(NX,NY), B;
	A=0.5;
	B=atanh(A);

	if (softCompare(atanh(0.5),RESULT)) {
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
