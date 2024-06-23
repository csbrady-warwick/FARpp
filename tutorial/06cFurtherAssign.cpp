#include <iostream>
#include "far.h"

int main(){
  far::Array<int,2> myArray(2,2);

	far::generate(myArray,[](){return 6;});
	std::cout << "Assigning by generation function that will always yield 6 gives : " << myArray << "\n";

	far::for_each(myArray,[](int &i){i*=2;});
	std::cout << "Assigning using for_each and a function that multiplies every element by 2 gives : " << myArray << "\n";

	far::iota(myArray,1);
	std::cout << "Assigning using iota starting from 1 gives : " << myArray << "\n";

}
