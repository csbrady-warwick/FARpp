#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main(){

	std::cout << "Testing all with reduction along one rank\n";
  Array<bool,2> A(NX,NY);
	Array<bool,1> B;

	//Check array
	A=true;
	B=all(A,1);
	if (!all(B==literal(true,true,true))) {
		std::cout << "Array failure\n";
		std::cout << "False negative\n";
		return -1;
	}

	A(1,2)=false;
	B=all(A,1);
  if (!all(B==literal(true,false,true))) { 
    std::cout << "Array failure\n";
    std::cout << "False positive in dim 1\n";
    return -1;
  }

  B=all(A,2);
  if (!all(B==literal(false,true,true))) {
    std::cout << "Array failure\n";
    std::cout << "False positive in dim 2\n";
    return -1;
  }


	Array<bool,1> C(10);
	C=true;
	std::cout << all(C,1) << std::endl;

	std::cout << "Tests passed\n\n";
}
