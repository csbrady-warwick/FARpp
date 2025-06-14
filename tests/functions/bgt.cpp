#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing bgt " << argv[0] << "\n";
#if defined(__cpp_lib_bit_cast) && __cpp_lib_bit_cast >= 201806L
	Array<int,2> A(NX,NY), B(NX,NY);
	A=2;B=1;
	if (!all(bgt(A,B))){
		std::cout << "2 BGT 1 failed\n";
		return -1;
	}
	A=1;B=2;
	if (any(bgt(A,B))){
		std::cout << "1 BGT 2 failed\n";
		return -1;
	}
	A=2;B=2;
	if (any(bgt(A,B))){
		std::cout << "2 BGT 2 failed\n";
		return -1;
	}

	A=-2;B=2;
	if (!all(bgt(A,B))){
		std::cout << "-2 BGT 2 failed\n";
		return -1;
	}

	A=2;B=-2;
	if (any(bgt(A,B))){
		std::cout << "2 BGT -2 failed\n";
		return -1;
	}
#endif
	std::cout << "Tests passed\n\n";
}
