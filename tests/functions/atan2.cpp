#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 0.4636476090008061162142562314612144020285370542861202638109330887

using namespace far;

int main(){
	std::cout << "Testing atan2\n";
	Array<double,2> A(NX,NY), B(NX,NY), C;
	A=1.0;
	B=2.0;
	C=atan2(A,B);

	if (softCompare(atan2(1.0,2.0),RESULT)) {
		std::cout << "Scalar failure\n";
		return -1;
	}

	if (softCompare(atan2(1.0,2.0),atan(1.0,2.0))){
		std::cout << "atan2 and two argument atan do not agree\n";
		return -1;
	}

	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (softCompare(C(i,j),RESULT)) {
				std::cout << "Array failure\n";
				return -1;
			}
		}
	std::cout << "Tests passed\n\n";
}
