#include <iostream>
#include "far.h"

int main(){
  far::Array<int,1> A = far::linspace<int>(1,10,10);

	std::cout << "Whole array = " << A << "\n";
	std::cout << "Elements 2 to 4 = " << A(far::Range(2,4)) << "\n"; //Fortran equivalent A(2:4)
	std::cout << "First 2 elements = " << A(far::Range(1,2)) << "\n"; // Fortran equivalent A(1:2)
	std::cout << "Start of array to element 2 = " << A(far::fromLB(2)) << "\n"; // Fortran equivalent A(:2)
}
