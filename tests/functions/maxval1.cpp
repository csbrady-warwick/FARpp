#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

	std::cout << "Testing maxval " << argv[0] << "\n";

    Array<int,2> A = reshape(linspace(1,9,9),3,3);

	if (maxval(A) != 9) {
		std::cout << "maxval test failed\n";
		return 1;
	}
	A(2,2) = 10;
	if (maxval(A) != 10) {
		std::cout << "maxval test failed\n";
		return 1;
	}
	A=-A;
	if (maxval(A) != -1) {
		std::cout << "maxval test failed\n";
		return 1;
	}

	A=reshape(linspace(1,9,9),3,3);
	Array<bool,2> B(3,3);
	B=true;
	if (maxval_with_mask(A,B) != 9) {
		std::cout << "maxval with mask test failed\n";
		return 1;
	}

	B=A<5;
	if (maxval_with_mask(A,B) != 4) {
		std::cout << "maxval with mask test failed\n";
		return 1;
	}

	std::cout << "maxval test passed\n\n";

}
