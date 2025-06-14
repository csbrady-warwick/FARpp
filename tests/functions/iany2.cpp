#include <iostream>
#include "far.h"
#include "compare.h"
#include <bitset>

#define NX 2
#define NY 2

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing iany with partial reduction " << argv[0] << "\n";
	Array<uint16_t,2> A(NX,NY);

	A(1,Range())=0b01010101;
	A(2,Range())=0b10101010;

	if (any(iany(A,1)!= 255)){
		std::cout << "Array failure\n";
  		std::cout << "False positive\n";
   		return -1;
	}

	if (any(iany(A,2)!= literal(85,170))) {
		std::cout << "Array failure\n";
  		std::cout << "False positive\n";
   		return -1;
	}

	Array<bool,2> mask(NX,NY);
	mask = true;
	if (any(iany_with_mask(A,2,mask)!= literal(85,170))){
		std::cout << "Array failure\n";
  		std::cout << "Mask (all active) failure\n";
   		return -1;
	}

	mask(2,Range()) = false;

	if (any(iany_with_mask(A,2,mask)!= literal(85,0))){
		std::cout << "Array failure\n";
  		std::cout << "Mask (some active) failure\n";
   		return -1;
	}

	std::cout << "Tests passed\n\n";

}
