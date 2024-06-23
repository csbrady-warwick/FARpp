#include <iostream>
#include "far.h"
#include "compare.h"
#include <bitset>

using namespace far;

int main(){
	std::cout << "Testing iany with full reduction\n";
	Array<uint8_t,1> A(2);

	A(1)=0b01010101;
	A(2)=0b10101010;

	if (iany(A)!= 0b11111111){
		std::cout << "Array failure\n";
  		std::cout << "False positive\n";
   		return -1;
	}

	A(2)=0;
	if (iany(A)!= 0b01010101){
		std::cout << "Array failure\n";
  		std::cout << "False negative\n";
   		return -1;
	}

	A(2) = 0b10101010;
	Array<bool,1> mask(2);
	mask = true;
	if (iany_with_mask(A,mask)!= 0b11111111){
		std::cout << "Array failure\n";
  		std::cout << "Mask (all active) failure\n";
   		return -1;
	}

	mask(1)=false;
	if (iany_with_mask(A,mask)!= 0b10101010){
		std::cout << "Array failure\n";
  		std::cout << "Mask (one active) failure\n";
   		return -1;
	}


	std::cout << "Tests passed\n\n";

}
