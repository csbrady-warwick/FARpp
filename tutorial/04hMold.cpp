#include <iostream>
#include "far.h"
#include <string>

int main(){

	far::Array<std::string,2> A(4,7);
	far::Array<int,2> B;
	B.mold(A);

	std::cout << far::shape(B) << "\n";

}
