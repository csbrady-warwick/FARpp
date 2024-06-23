#include <iostream>
#include "far.h"

int main(){
  far::Array<int,2> A = reshape(far::linspace<int>(1,25,25),5,5);

	//far::gridPrint is a method for printing a rank 2 array with some information about the bounds
	std::cout << far::gridPrint(A) << "\n\n";

	//Now print just a slice
	std::cout << far::gridPrint(A(far::Range(2,4),far::Range(2,4))) << "\n";

}
