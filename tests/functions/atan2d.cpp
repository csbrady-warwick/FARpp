#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT 0.4636476090008061162142562314612144020285370542861202638109330887/M_PI*180.0

using namespace far;

int main(){
	std::cout << "Testing atan2d\n";
	Array<double,2> A(NX,NY), B(NX,NY), C;
	A=1.0;
	B=2.0;
	C=atan2d(A,B);

	if (softCompare(atan2d(1.0,2.0),RESULT)) {
		std::cout << "Scalar failure\n";
		return -1;
	}

	if (softCompare(atan2d(1.0,2.0),atand(1.0,2.0))){
		std::cout << "atan2d and two argument atand do not agree\n";
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
