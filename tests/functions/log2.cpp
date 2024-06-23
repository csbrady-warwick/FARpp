#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 0.3033423944873308442519478750028742960943477170149423984877571452

using namespace far;

int main(){
	std::cout << "Testing log2\n";
  	Array<double,2> A(NX,NY), B;
	A=1.234;
	B=log2(A);

	if (softCompare(log2(1.234),RESULT)) {
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
