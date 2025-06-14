#include <iostream>
#include "far.h"
#include "compare.h"
#include <complex>
#include "demangle.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

	std::cout << "Testing cmplx " << argv[0] << "\n";
	Array<std::complex<double>,2> A(NX,NY);
	Array<double,2> R(NX,NY),I(NX,NY);
	R=1;I=2;

	if (softCompare(cmplx(1.0,2.0),std::complex<double>(1.0,2.0))) {
		std::cout << "Scalar failure\n";
		return -1;
	}

	A=cmplx(1.0);
	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (softCompare(A(i,j),std::complex<double>(1.0,0.0))) {
				std::cout << A(i,j) << "\n";
				std::cout << "Array failure setting real\n";
				return -1;
			}
		}

	A=cmplx(std::complex<double>(1.0,2.0));
	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (softCompare(A(i,j),std::complex<double>(1.0,2.0))) {
				std::cout << A(i,j) << "\n";
				std::cout << "Array failure setting complex\n";
				return -1;
			}
		}

	A=cmplx(1.0,2.0);
	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (softCompare(A(i,j),std::complex<double>(1.0,2.0))) {
				std::cout << A(i,j) << "\n";
				std::cout << "Array failure setting real and imaginary\n";
				return -1;
			}
		}

	A=cmplx(R,I);
	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (softCompare(A(i,j),std::complex<double>(1.0,2.0))) {
				std::cout << A(i,j) << "\n";
				std::cout << "Array failure setting array real and imaginary parts\n";
				return -1;
			}
		}

	std::cout << "Tests passed\n\n";
}
