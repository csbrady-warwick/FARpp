#include <iostream>
#include "far.h"

int main(){
	far::Array<int,2> A;
	A=far::zeros(3,3); // Make a 3x3 element array of all zeros
	std::cout << A << "\n";

	A=far::ones(5,5); // Make a 5x5 element array of all ones
	std::cout << A << "\n";
}
