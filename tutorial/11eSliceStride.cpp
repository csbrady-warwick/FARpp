#include <iostream>
#include "far.h"

int main(){
  far::Array<int,2> A = reshape(far::linspace<int>(1,25,25),5,5);

	std::cout << far::gridPrint(A) << "\n\n";

  A(far::Range(2,4,2),far::Range(2,4,3)) = -5;

	std::cout << far::gridPrint(A) << "\n";

}
