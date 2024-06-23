#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main(){
	std::cout << "Testing logical\n";
	Array<int,2> A(NX,NY);
	Array<bool,2> B;
	A=1;

	if (logical(1)!=true) {
		std::cout << "logical(1) = " << logical(1) << "\n";
		std::cout << "Scalar failure\n";
		return -1;
	}

	if (logical(0)!=false) {
		std::cout << "logical(0) = " << logical(0) << "\n";
		std::cout << "Scalar failure\n";
		return -1;
	}

	{
		auto ftest = logical(1);
		if constexpr(!std::is_same_v<decltype(ftest),bool>){
			std::cout << "Type of logical(1) is not bool\n";
			std::cout << "Scalar failure\n";
			return -1;
		}
	}

	B=logical(A);
	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (B(i,j)!=true) {
				std::cout << "Array failure\n";
				return -1;
			}
		}
	std::cout << "Tests passed\n\n";
}
