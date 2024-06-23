#include <iostream>
#include "far.h"
#include "compare.h"
#include <complex>
#include "demangle.h"

#define NX 3
#define NY 3

using namespace far;

int main(){

	std::cout << "Testing aimag\n";
  Array<std::complex<double>,2> A(NX,NY);
	Array<double,2> B;
	A=std::complex<double>(1.0,2.0);
	B = aimag(A);

	if (softCompare(aimag(std::complex<double>(1.0,2.0)),2.0)) {
		std::cout << "Scalar failure\n";
		return -1;
	}

	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (softCompare(B(i,j),2.0)) {
				std::cout << B(i,j) << "\n";
				std::cout << "Array failure\n";
				return -1;
			}
		}
	std::cout << "Tests passed\n\n";
}
