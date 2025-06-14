#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing dprod " << argv[0] << "\n";
	{
		if (softCompare(dprod(1.2,1.4),1.2*1.4)) {
			std::cout << "Real failure\n";
			std::cout << "Scalar failure\n";
			return -1;
		}
	}

	{
		auto v = dprod(float(3),float(4));
		if constexpr(!std::is_same_v<decltype(v), double>){
			std::cout << "Type conversion failure\n";
			return -1;
		}
		if (softCompare(v,12.0)) {
			std::cout << "Float failure\n";
			std::cout << "Scalar failure\n";
			return -1;
		}

	}

	{
		Array<double,2> A(NX,NY);
		Array<double,2> B,C;
		A = reshape(linspace(1,NX*NY,NX*NY),NX,NY);
		B = A;
		C = dprod(A,B);
		for (int j=1;j<=NY;j++){
			for (int i=1;i<=NX;i++){
				if (softCompare(C(i,j),A(i,j)*B(i,j))) {
					std::cout << "Array failure\n";
					return -1;
				}
			}
		}
	}
	
	std::cout << "Tests passed\n\n";
}
