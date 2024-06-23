#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 4
#define NY 4
#define RESULT 2305843009213693966

using namespace far;

int main(){
	std::cout << "Testing dshiftr\n";
	{
		int64_t A = 57, B = 117;
		int64_t v = dshiftr(A,B,3);
		if (v!=RESULT) {
			std::cout << "Scalar failure\n";
			return -1;
		}
	}
	{
		Array<int64_t,2> A(NX,NY), B(NX,NY);
		Array<int64_t,2> C;
		A = 57;
		B = 117;
		C = dshiftr(A,B,3);
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
