#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 0.0913151596972228772592050619999463466527633125644262249421834666

using namespace far;

int main(){
	std::cout << "Testing log10\n";
  	Array<double,2> A(NX,NY), B;
	A=1.234;
	B=log10(A);

	if (softCompare(log10(1.234),RESULT)) {
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
