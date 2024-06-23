#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main(){
	std::cout << "Testing nint\n";
	Array<double,2> A(NX,NY);
	Array<int,2> B;
	A=1.5;

	if (nint(1.5)!=2) {
		std::cout << "nint(1.5) = " << nint(1.5) << "\n";
		std::cout << "Scalar failure\n";
		return -1;
	}

	if (nint(-1.5)!=-2) {
		std::cout << "nint(-1.5) = " << f_int(-1.5) << "\n";
		std::cout << "Scalar failure\n";
		return -1;
	}

	if (nint(std::complex<double>(1.5,7.2))!=2) {
		std::cout << "f_int(std::complex<double>(1.5,7.2)) = " << nint(std::complex<double>(1.5,0)) << "\n";
		std::cout << "Scalar failure\n";
		return -1;
	}

	{
		auto ftest = nint(1.5);
		if constexpr(!std::is_same_v<decltype(ftest),int64_t>){
			std::cout << "Type of nint(1.5) is not int\n";
			std::cout << "Scalar failure\n";
			return -1;
		}
	}

	{
		auto ftest = nint<int>(1.5);
		if constexpr(!std::is_same_v<decltype(ftest),int>){
			std::cout << "Type of nint<int64_t>(1.5) is not int64_t\n";
			std::cout << "Scalar failure\n";
			return -1;
		}
	}

	B=nint(A);
	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (B(i,j)!=2) {
				std::cout << "Array failure\n";
				return -1;
			}
		}
	std::cout << "Tests passed\n\n";
}
