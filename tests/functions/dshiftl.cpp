#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 4
#define NY 4
#define RESULT 448

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing dshiftl " << argv[0] << "\n";
	{
		int64_t A = 56, B = 117;
		int64_t v = dshiftl(A,B,3);
		if (v!=RESULT) {
			std::cout << "Scalar failure\n";
			return -1;
		}
	}
	{
		Array<int64_t,2> A(NX,NY), B(NX,NY);
		Array<int64_t,2> C;
		A = 56;
		B = 117;
		C = dshiftl(A,B,3);
		for (int j=1;j<=NY;j++){
			for (int i=1;i<=NX;i++){
				if (C(i,j)!=RESULT) {
					std::cout << "Array failure\n";
					return -1;
				}
			}
		}
	}
	std::cout << "Tests passed\n\n";
}
