#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing aint " << argv[0] << "\n";
  Array<double,2> A(NX,NY);
	Array<int,2> B;
	A=1.5;
	B=aint(A);

	if (aint(1.5)!=1) {
		std::cout << "aint(1.5) = " << aint(1.5) << "\n";
		std::cout << "Scalar failure\n";
		return -1;
	}

	if (aint(-1.5)!=-1){
		std::cout << "aint(-1.5) = " << aint(-1.5) << "\n";
    std::cout << "Scalar failure\n";
    return -1;
	}

	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (B(i,j)!=1) {
				std::cout << "Array failure\n";
				return -1;
			}
		}
	std::cout << "Tests passed\n\n";
}
