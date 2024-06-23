#include <iostream>
#include "far.h"

int main(){
  far::Array<int,1> Array1 = far::linspace<int>(1,10,10);
	far::Array<int,1> Array2 = far::linspace<int>(10,1,10);

	std::cout << "Array 1 = " << Array1 << "\n";
	std::cout << "Array 2 = " << Array2 << "\n";
	auto ArrayR = far::toArray(Array1 + Array2); //toArray converts the lazyArray to an Array so that ArrayR is a proper array
	std::cout << "Array 1 + Array 2 = " << ArrayR << "\n";
}
