#include <iostream>
#include "far.h"

int main(){
  far::Array<int,2> myArray;
	//reallocate(myArray,3,3); // This line will cause a runtime error because myArray is not allocated
	allocate(myArray,2,2); //This line will work because we are allocating an unallocated array
	//allocate(myArray,3,3); // This line will cause a runtime error because you cannot allocate an already allocated array
	reallocate(myArray,3,3); //This line will work because we are reallocating an allocated array
}
