#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main(){
	std::cout << "Testing dot_product\n";
	{
		Array<double,1> A(NX), B(NX);
		A=linspace(1.0,double(NX),NX);
		B=A;
		if (softCompare(dot_product(A,B),14)) {
			std::cout << "Real failure\n";
			std::cout << "Array failure\n";
			return -1;
			}
	}

	{
		Array<std::complex<double>,1> A(NX), B(NX);
		A=cmplx(linspace(1.0,double(NX),NX),linspace(1.0,double(NX),NX));
		B=A;
		if (softCompare(dot_product(A,B),
				std::complex<double>(28.0,0.0))) {
			std::cout << "Complex failure\n";
			std::cout << "Array failure\n";
			return -1;
		}
	}

	{
		Array<bool,1> A(NX), B(NX);
		A = literal(true,false,true);
		B = literal(true,true,false);
		if (dot_product(A,B)!=true) {
			std::cout << "Bool failure\n";
			std::cout << "False negative\n";
			std::cout << "Array failure\n";
			return -1;
		}
		B=!A;
		if (dot_product(A,B)!=false) {
			std::cout << "Bool failure\n";
			std::cout << "False positive\n";
			std::cout << "Array failure\n";
			return -1;
		}
	}


	std::cout << "Tests passed\n\n";
}
