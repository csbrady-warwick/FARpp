#include <iostream>
#include "far.h"
#include "compare.h"
#include <bitset>

#define NX 2
#define NY 2

using namespace far;

int main(){
	std::cout << "Testing iall with partial reduction\n";
	Array<uint16_t,2> A(NX,NY);

	A(1,Range())=0b01010101;
	A(2,Range())=0b10101010;

	if (any(iall(A,1)!= literal(0,0))) {
		std::cout << "Array failure\n";
  		std::cout << "False positive\n";
   		return -1;
	}

	if (any(iall(A,2)!= literal(85,170))) {
		std::cout << "Array failure\n";
  		std::cout << "False positive\n";
   		return -1;
	}

	Array<bool,2> mask(NX,NY);
	mask = true;
	if (any(iall_with_mask(A,2,mask)!= literal(85,170))){
		std::cout << "Array failure\n";
  		std::cout << "Mask (all active) failure\n";
   		return -1;
	}

	mask(2,Range()) = false;
	if (any(iall_with_mask(A,1,mask)!= literal(85,85))){
		std::cout << "Array failure\n";
  		std::cout << "Mask (some active) failure\n";
   		return -1;
	}

	std::cout << "Tests passed\n\n";

}