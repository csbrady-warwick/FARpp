#include <iostream>
#include "far.h"
#include "compare.h"
#include <bitset>

using namespace far;

int main(){
	std::cout << "Testing iparity with full reduction\n";
	Array<uint8_t,1> A(2);

	A(1)=0b01010101;
	A(2)=0b10101010;

	if (iparity(A)!= 0b11111111){
		std::cout << "Array failure\n";
  		std::cout << "Or failure\n";
   		return -1;
	}

	A(2)=0;
	if (iparity(A)!= 0b01010101){
		std::cout << "Array failure\n";
  		std::cout << "Or failure 2\n";
   		return -1;
	}

	A(2) = 0b01010101;
	if (iparity(A)!= 0){
		std::cout << "Array failure\n";
  		std::cout << "XOR failure\n";
   		return -1;
	}
	Array<bool,1> mask(2);
	mask = true;
	A(2)=0b10101010;
	if (iparity_with_mask(A,mask)!= 0b11111111){
		std::cout << "Array failure\n";
  		std::cout << "Mask (all active) failure\n";
   		return -1;
	}	

	mask(1)=false;
	if (iparity_with_mask(A,mask)!= 0b10101010){
		std::cout << "Array failure\n";
  		std::cout << "Mask (one active) failure\n";
   		return -1;
	}


	std::cout << "Tests passed\n\n";

}
