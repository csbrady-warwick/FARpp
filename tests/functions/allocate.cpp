#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing allocate, deallocate and allocated " << argv[0] << "\n";
  Array<int,2> A(NX,NY);
	
	if (!allocated(A)) {
		std::cout << "Failed allocated check on constructed array\n";
		return -1;
	}

	Array<int,2> B;
	if (allocated(B)) {
		std::cout << "Failed allocated check on unallocated array\n";
		return -1;
	}

	allocate(B,NX,NY);
	if (!allocated(B)) {
		std::cout << "Failed allocated check on array allocated with \"allocate\"\n";
		return -1;
	}

	Array<int,2> C;
	C=B;
	if (!allocated(C)) {
		std::cout << "Failed allocated check on array allocated by assignment\n";
		return -1;
	}

	deallocate(B);
	if (allocated(B)) {
		std::cout << "Failed allocated check after deallocation\n";
		return -1;
	}

	if (!allocated(C)) {
		std::cout << "Failed allocated check on array allocated by assignment after deallocation of source array\n";
		return -1;
	}

	Array<int,2> D;
	D.mold(C);
	if (!allocated(D)){
		std::cout << "Failed allocated check on array allocated by mold\n";
	}
	std::cout << "Tests passed\n\n";

}
