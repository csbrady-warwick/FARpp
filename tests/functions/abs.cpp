#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main(){

	std::cout << "Testing abs\n";
  Array<double,2> A(NX,NY), B;
	A=-1;
	B=abs(A);

	if (abs(-4)!=4) {
		std::cout << "Scalar failure\n";
		return -1;
	}

	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (B(i,j)!=1) {
				std::cout << "Array failure\n";
				return -1;
			}
		}
	std::cout << "Tests passed\n\n";
}
