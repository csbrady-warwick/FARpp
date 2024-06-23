#include <iostream>
#include "far.h"

int main(){
  far::Array<int,2> myArray(2,2); // Have to allocate array before assignment when assigning from non-array type

	myArray = 14; //Assign it
	std::cout << "Assign whole array to 14 gives : " << myArray << "\n";

}
