#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT1 -0.781212821300288716547150000047964820549906390716444607843833246
#define RESULT2 -1.650682606816254391077226766119444803927630304523564762398710339
#define RESULT4 -33.27842302897211869549331562045944156703605865974332188810733834
#define RESULT7 -30588.95705212398884088006759256472715998978197570076265625252807

using namespace far;

int main(){
	std::cout << "Testing bessel_yn\n";
  Array<double,2> A(NX,NY), B;
	A=1.0;
	B=bessel_yn(4,A);

	if (softCompare(bessel_yn(4,1.0),RESULT4)) {
		std::cout << "Scalar failure j=4\n";
		return -1;
	}

	if (softCompare(bessel_yn(7,1.0),RESULT7)) {
		std::cout << "Scalar failure j=4\n";
		return -1;
	}	

	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (softCompare(B(i,j),RESULT4)) {
				std::cout << "Array failure\n";
				return -1;
			}
		}
	//Check second form

	Array<double, 1> Results;
	Results = bessel_yn(1,2,1.0);
	bool pass = true;
	pass = pass && !softCompare(Results(1),RESULT1);
	pass = pass && !softCompare(Results(2),RESULT2);
	if (!pass) {
		std::cout << "Second form failure\n";
		return -1;
	}
	std::cout << "Tests passed\n\n";
}
