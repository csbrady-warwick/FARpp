#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

//This algorithm is completely different from the one in the FAR++ library
//It should be a good test to see if the FAR++ library is working correctly
template <typename TU, typename TV>
Array<int,2> shift(Array<int,2> &A, TU U, TV V, int boundary=0) {
	Array<int,2> B(NX,NY);
	for (size_t j=1; j<=NX; j++) {
		for (size_t i=1; i<=NY; i++) {
			int64_t shiftU;
			if constexpr (arrayInfo<TU>::value) {
				shiftU = (i + U(j));
			} else {
				shiftU = (i + U);
			}
			int64_t shiftV;
			if constexpr (arrayInfo<TV>::value) {
				shiftV = (j + V(i));
			} else {
				shiftV = (j + V);
			}
			if (shiftU < 1 || shiftU > NX || shiftV < 1 || shiftV > NY) {
				B(i,j)=boundary;
			} else {
				B(i,j)=A(shiftU,shiftV);
			}
		}
	}
	return B;
}

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing eoshift with boundary " << argv[0] << "\n";
	Array<int,1> src(NX*NY);
	Array<int,2> A(NX,NY), B(NX,NY), C;

	for (size_t i=1; i<=NX*NY; i++) {
		src(i)=i;
	}
	A=reshape(src,NX,NY);

	B=shift(A,1,0,14); //Use simple shift
	C=eoshift_with_boundary(A,1,14);
	if (!all(B==C)) {
		std::cout << "Array failure - positive X shift\n";
		return -1;
	}

	B=shift(A,-1,0,14); //Use simple shift
	C=eoshift_with_boundary(A,-1,14);
	if (!all(B==C)) {
		std::cout << "Array failure - negative X shift\n";
		return -1;
	}

	B=shift(A,0,1,14); //Use simple shift
	//The FAR version of cshift uses the Fortran syntax of shift and direction
	C=eoshift_with_boundary(A,1,14,2);
	if (!all(B==C)) {
		std::cout << "Array failure - positive Y shift\n";
		return -1;
	}

	B=shift(A,0,-1,14); //Use simple shift
	C=eoshift_with_boundary(A,-1,14,2);
	if (!all(B==C)) {
		std::cout << "Array failure - negative Y shift\n";
		return -1;
	}

	//Test with Array shifts
	Array<int,1> U(NX), V(NY);
	for (size_t i=1; i<=NX; i++) {
		U(i)=i-1;
	}

	B=shift(A,U,0,14); //Use simple shift
	C=eoshift_with_boundary(A,U,14);
	if (!all(B==C)) {
		std::cout << "Array failure - positive X shift with per row shift\n";
		return -1;
	}

	for (size_t i=1; i<=NY; i++) {
		V(i)=-(i-1);
	}
	B=shift(A,0,V,14); //Use simple shift
	C=eoshift_with_boundary(A,V,14,2);
	if (!all(B==C)) {
		std::cout << "Array failure - negative Y shift with per column shift\n";
		return -1;
	}

	std::cout << "Tests passed\n\n";

}
