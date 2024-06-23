#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main(){
	std::cout << "Testing associated\n";
  	Array<int,2> A(NX,NY), C(NX,NY);
	Array<int,2> B;

	if (associated(B)){
		std::cout << "False positive, associated (no target)\n";
		return -1;
	}

	B.pointTo(A);
	if (!associated(B)){
		std::cout << "False negative, not associated (no target)\n";
		return -1;
	}

	if (associated(B,C)){
		std::cout << "False positive, associated (with target)\n";
		return -1;
	}

	if (!associated(B,A)){
		std::cout << "False negative, not associated (with target)\n";
		return -1;
	}

	deallocate(C);
	C.pointTo(A);
	if (!associated(B,C)){
		std::cout << "False negative, not associated (two pointers)\n";
		return -1;
	}

	B.pointTo(A(Range(1,2),Range(1,2)));
	if (!associated(B)){
		std::cout << "False negative, not associated (subarray)\n";
		return -1;
	}

	if (associated(B,A)){
		std::cout << "False positive, associated (subarray)\n";
		return -1;
	}

	if (!associated(B,A(Range(1,2),Range(1,2)))){
		std::cout << "False negative, not associated (subarray)\n";
		return -1;
	}
	
	std::cout << "Tests passed\n\n";

}
