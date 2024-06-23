#include <iostream>
#include "far.h"

int main(){
  far::Array<int,2> A = reshape(far::linspace<int>(1,25,25),5,5);

	std::cout << far::gridPrint(A) << "\n\n";
	std::cout << far::gridPrint(A(far::Range(4,2,-1),far::Range(4,2,-1))) << "\n";

}
