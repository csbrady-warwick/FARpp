#include <iostream>
#include "far.h"

int main(){
  far::Array<int,2> A = reshape(far::linspace<int>(1,25,25),5,5);

	std::cout << far::gridPrint(A) << "\n\n";

  A(far::Range(2,4),far::Range(2,4)) = -5; //Set all values in the slice to -5

	std::cout << far::gridPrint(A) << "\n";

}
