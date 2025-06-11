#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 0.0882569642156769579829267660235151628278175230906755467110438476

using namespace far;

int main(){
	std::cout << "Testing bessel_y0\n";
#if !defined(FAR_NEED_BOOST_MATHS) || defined(FAR_HAS_BOOST_MATHS)
  Array<double,2> A(NX,NY), B;
	A=1.0;
	B=bessel_y0(A);

	if (softCompare(bessel_y0(1.0),RESULT)) {
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
#endif
	std::cout << "Tests passed\n\n";
}
