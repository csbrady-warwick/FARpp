#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main(){

	std::cout << "Testing ichar\n";
	Array<char,2> A(NX,NY);
	Array<int,2> B;
	A='c';
	B=ichar(A);

	if ('d'!=ichar('d')) {
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
