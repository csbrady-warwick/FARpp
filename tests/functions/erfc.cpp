#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 0.0808376035864341574126769073554035858572762337240346131425742441

using namespace far;

int main(){
	std::cout << "Testing erfc\n";
	Array<double,2> A(NX,NY), B;
	A=1.2345;
	B=erfc(A);

	if (softCompare(erfc(1.2345),RESULT)) {
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
