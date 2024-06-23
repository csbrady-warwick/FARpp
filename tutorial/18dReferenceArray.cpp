#include <iostream>
#include "far.h"

int main(){

	//Create a normal array
	far::Array<int ,2> A = far::reshape(far::linspace(1,10,10),2,5);
	//Create an array of references
	far::Array<int&,2> B;

	//This is the key line. This binds the array of references to the array A
	//After this is done, B is a reference to A and cannot be made to refer to anything else
	//Any changes to B no propagate to A
	B=A;

	std::cout << far::gridPrint(B) << "\n";

	//This changes the value of A	
	B=14;

	std::cout << far::gridPrint(A) << "\n";

}
