#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3
#define RESULT1 0.4400505857449335159596822037189149131273723019927652511367581717
#define RESULT2 0.1149034849319004804696468813351666053454703142302052604119687944
#define RESULT4 0.0024766389641099550437850483953424441815834153381294826547332414
#define RESULT7 0.0000015023258174368082122186334680484018447814030746246263232623

using namespace far;

int main(){
	std::cout << "Testing bessel_jn\n";
  Array<double,2> A(NX,NY), B;
	A=1.0;
	B=bessel_jn(4,A);

	if (softCompare(bessel_jn(4,1.0),RESULT4)) {
		std::cout << "Scalar failure j=4\n";
		return -1;
	}

	if (softCompare(bessel_jn(7,1.0),RESULT7)) {
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
	Results = bessel_jn(1,2,1.0);
	bool pass = true;
	pass = pass && !softCompare(Results(1),RESULT1);
	pass = pass && !softCompare(Results(2),RESULT2);
	if (!pass) {
		std::cout << "Second form failure\n";
		return -1;
	}
	std::cout << "Tests passed\n\n";
}
