#include <iostream>
#include "far.h"

int main(){
  far::Array<int,2> A = -reshape(far::linspace<int>(1,25,25),5,5);
	std::cout << far::gridPrint(A) << "\n\n";

	std::cout << far::gridPrint(far::abs(A)(far::Range(2,4,-2),far::Range(2,4,-2))) << "\n";
}
