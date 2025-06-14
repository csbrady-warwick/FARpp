#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
	std::cout << "Testing any with full reduction " << argv[0] << "\n";
  Array<bool,2> A(NX,NY);

	if (!any(true)) {
		std::cout << "Scalar failure\n";
		std::cout << "Scalar false negative\n";
		return -1;
	}

	if (any(false)){
    std::cout << "Scalar failure\n";
		std::cout << "Scalar false positive\n";
    return -1;
	}

	//Check array
	A=true;
	if (!any(A)) {
		std::cout << "Array failure\n";
		std::cout << "False negative on whole array\n";
		return -1;
	}

	A=false;
  if (any(A)) { 
    std::cout << "Array failure\n";
    std::cout << "False positive on whole array\n";
    return -1;
  }

  //Check array
  A=false;
	A(NX,NY) = true;
  if (!any(A)) {
    std::cout << "Array failure\n";
    std::cout << "False negative on single error\n";
    return -1;
  }

  std::cout << "Tests passed\n\n";

}
