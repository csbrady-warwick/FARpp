#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main(){
	std::cout << "Testing count with full reduction\n";
	Array<bool,2> A(NX,NY);

	if (count(true)!=1) {
		std::cout << "Scalar failure\n";
		std::cout << "Scalar false negative\n";
		return -1;
	}

	if (count(false)!=0){
    std::cout << "Scalar failure\n";
		std::cout << "Scalar false positive\n";
    return -1;
	}

	//Check array
	A=true;
	if (count(A)!=NX*NY) {
		std::cout << "Array failure\n";
		std::cout << count(A) << "\n";
		std::cout << "False negative\n";
		//return -1;
	}

	A(NX,NY)=false;
  if (count(A)!=NX*NY-1) { 
    std::cout << "Array failure\n";
    std::cout << "False positive\n";
    return -1;
  }
	std::cout << "Tests passed\n\n";

}
