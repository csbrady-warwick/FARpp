#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main(){
	std::cout << "Testing f_int\n";
	Array<double,2> A(NX,NY);
	Array<int,2> B;
	A=1.5;

	if (f_int(1.5)!=1) {
		std::cout << "f_int(1.5) = " << f_int(1.5) << "\n";
		std::cout << "Scalar failure\n";
		return -1;
	}

	if (f_int(-1.5)!=-1) {
		std::cout << "f_int(-1.5) = " << f_int(-1.5) << "\n";
		std::cout << "Scalar failure\n";
		return -1;
	}

	if (f_int(std::complex<double>(1.5,7.2))!=1) {
		std::cout << "f_int(std::complex<double>(1.5,7.2)) = " << f_int(std::complex<double>(1.5,0)) << "\n";
		std::cout << "Scalar failure\n";
		return -1;
	}

	{
		auto ftest = f_int(1.5);
		if constexpr(!std::is_same_v<decltype(ftest),int>){
			std::cout << "Type of f_int(1.5) is not int\n";
			std::cout << "Scalar failure\n";
			return -1;
		}
	}

	{
		auto ftest = f_int<int64_t>(1.5);
		if constexpr(!std::is_same_v<decltype(ftest),int64_t>){
			std::cout << "Type of f_int<int64_t>(1.5) is not int64_t\n";
			std::cout << "Scalar failure\n";
			return -1;
		}
	}

	B=f_int(A);
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
