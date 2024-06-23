#include <iostream>
#include "far.h"

int main(){
  far::Array<int,1> Array = far::linspace<int>(1,10,10);

	std::cout << "Array = " << Array << "\n";
	std::cout << "1 + Array = " << 1+Array << "\n";
}
