#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main(){
	std::cout << "Testing all with full reduction\n";
  Array<bool,2> A(NX,NY);

	if (!all(true)) {
		std::cout << "Scalar failure\n";
		std::cout << "Scalar false negative\n";
		return -1;
	}

	if (all(false)){
    std::cout << "Scalar failure\n";
		std::cout << "Scalar false positive\n";
    return -1;
	}

	//Check array
	A=true;
	if (!all(A)) {
		std::cout << "Array failure\n";
		std::cout << "False negative\n";
		return -1;
	}

	A(NX,NY)=false;
  if (all(A)) { 
    std::cout << "Array failure\n";
    std::cout << "False positive\n";
    return -1;
  }
	std::cout << "Tests passed\n\n";

}
