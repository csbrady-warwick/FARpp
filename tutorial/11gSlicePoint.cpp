#include <iostream>
#include "far.h"

int main(){
  far::Array<int,2> A = reshape(far::linspace<int>(1,25,25),5,5);
	far::Array<int,2> dest;

	std::cout << far::gridPrint(A) << "\n\n";
	//This does NOT copy the slice. dest is now a pointer to the slice of A
	dest.pointTo(A(far::Range(2,4),far::Range(2,4)));

  dest = -5; //Set all values in the slice to -5

	//Print A, the (2:4,2:4) section will have been changed
	std::cout << far::gridPrint(A) << "\n";
}
