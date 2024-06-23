#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main(){

	std::cout << "Testing dble\n";
	Array<int,2> A(NX,NY);
	Array<double,2> B(NX,NY);
	Array<std::complex<double>,2> C(NX,NY);
	A=4;
	B=dble(A);

	if (dble(-2)!=-2.0) {
		std::cout << "Scalar failure\n";
		return -1;
	}

	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (B(i,j)!=4.0) {
				std::cout << "Array failure\n";
				return -1;
			}
		}

	C=std::complex<double>(4,5);
	B=dble(C);
	if (B(1,1)!=4.0) {
		std::cout << "Array failure\n";
		return -1;
	}
	std::cout << "Tests passed\n\n";
}
