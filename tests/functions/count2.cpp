#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

	std::cout << "Testing all with reduction along one rank " << argv[0] << "\n";
	Array<bool,2> A(NX,NY);
	Array<size_t,1> B;

	//Check array
	A=true;
	B=count(A,1);
	if (!all(B==literal<size_t>(3,3,3))) {
		std::cout << "Array failure\n";
		std::cout << "False negative\n";
		return -1;
	}

	A(1,2)=false;
	B=count(A,1);
  	if (!all(B==literal<size_t>(3,2,3))) {
    	std::cout << "Array failure\n";
    	std::cout << "False positive in dim 1\n";
    	return -1;
  	}

  B=count(A,2);
  if (!all(B==literal<size_t>(2,3,3))) {
    std::cout << "Array failure\n";
    std::cout << "False positive in dim 2\n";
    return -1;
  }
	std::cout << "Tests passed\n\n";
}
