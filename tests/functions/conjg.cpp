#include <iostream>
#include "far.h"
#include "compare.h"
#include <complex>
#include "demangle.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

	std::cout << "Testing conjg " << argv[0] << "\n";
	Array<std::complex<double>,2> A(NX,NY);

	if (softCompare(conjg(cmplx(1.0,2.0)),std::complex<double>(1.0,-2.0))) {
		std::cout << "Scalar failure\n";
		return -1;
	}

	A=cmplx(1.0,2.0);
	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (softCompare(conjg(A(i,j)),std::complex<double>(1.0,-2.0))) {
				std::cout << A(i,j) << "\n";
				std::cout << "Array failure\n";
				return -1;
			}
		}

	std::cout << "Tests passed\n\n";
}
