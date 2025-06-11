#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 0.4400505857449335159596822037189149131273723019927652511367581717

using namespace far;

int main(){
	std::cout << "Testing bessel_j1\n";
#if !defined(FAR_NEED_BOOST_MATHS) || defined(FAR_HAS_BOOST_MATHS)
  Array<double,2> A(NX,NY), B;
	A=1.0;
	B=bessel_j1(A);

	if (softCompare(bessel_j1(1.0),RESULT)) {
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
