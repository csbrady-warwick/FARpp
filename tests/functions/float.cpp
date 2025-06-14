#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing f_float " << argv[0] << "\n";
	Array<double,2> A(NX,NY);
	Array<float,2> B;
	A=1.5;

	if (softCompare(f_float(1.5),1.5)) {
		std::cout << "f_float(1.5) = " << f_float(1.5) << "\n";
		std::cout << "Scalar failure\n";
		return -1;
	}

	auto ftest = f_float(1.5);
	if constexpr(!std::is_same_v<decltype(ftest),float>){
		std::cout << "Type of float(1.5) is not float\n";
		std::cout << "Scalar failure\n";
		return -1;
	}

	B=f_float(A);
	//Check array
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (softCompare(B(i,j),1.5)) {
				std::cout << "Array failure\n";
				return -1;
			}
		}
	auto C = toArray(f_float(A));
	if constexpr(!std::is_same_v<decltype(C),Array<float,2>>){
		std::cout << "Type of toArray(float(A)) is not Array<float,2>\n";
		std::cout << "Array failure\n";
		return -1;
	}
	std::cout << "Tests passed\n\n";
}
