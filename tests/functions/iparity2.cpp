#include <iostream>
#include "far.h"
#include "compare.h"
#include <bitset>

#define NX 2
#define NY 2

using namespace far;

int main(){
	std::cout << "Testing iparity with partial reduction\n";
	Array<uint16_t,2> A(NX,NY);

	A(1,Range())=0b01010101;
	A(2,Range())=0b10101010;

	if (any(iparity(A,1)!= 255)){
		std::cout << "Array failure\n";
  		std::cout << "False positive\n";
   		return -1;
	}

	if (any(iparity(A,2)!= 0)) {
		std::cout << "Array failure\n";
  		std::cout << "False positive\n";
   		return -1;
	}

	Array<bool,2> mask(NX,NY);
	mask = true;
	if (any(iparity_with_mask(A,2,mask)!= 0)){
		std::cout << "Array failure\n";
  		std::cout << "Mask (all active) failure\n";
   		return -1;
	}

	mask(Range(),2) = false;

	if (any(iparity_with_mask(A,2,mask)!= literal<uint16_t>(85,170))){
		std::cout << "Array failure\n";
  		std::cout << "Mask (some active) failure\n";
   		return -1;
	}
	std::cout << "Tests passed\n\n";

}
