#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

	std::cout << "Testing achar " << argv[0] << "\n";
  Array<char,2> A(NX,NY), B;
	A='c';
	B=achar(A);

	if ('d'!=achar('d')) {
		std::cout << "Scalar failure\n";
		return -1;
	}

	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (B(i,j)!='c') {
				std::cout << "Array failure\n";
				return -1;
			}
		}
	std::cout << "Tests passed\n\n";
}
