#include <iostream>
#include "far.h"

int main(){
	far::Array<int,1> A;
	A=far::zeros(10); // Make a 10 element array of all zeros
	std::cout << A << "\n";

	A=far::ones(4); // Make a 4 element array of all ones
	std::cout << A << "\n";
}
