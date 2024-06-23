#include <iostream>
#include "far.h"

int main(){
  far::Array<int,2> A = reshape(far::linspace<int>(1,25,25),5,5);
	far::Array<int,2> result;

	std::cout << far::gridPrint(A) << "\n\n";

	//This creates a new array holding the values in the selected device
	//This is the first point at which a copy of the data is made!
  result = A(far::Range(2,4),far::Range(2,4));

	std::cout << far::gridPrint(result) << "\n";

}
