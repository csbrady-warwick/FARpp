#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

	std::cout << "Testing minval " << argv[0] << "\n";

    Array<int,2> A = reshape(linspace(1,9,9),3,3);

	if (minval(A) != 1) {
		std::cout << "minval test failed(1)\n";
		return 1;
	}
	A(2,2) = -1;
	if (minval(A) != -1) {
		std::cout << "minval test failed(-1)\n";
		return 1;
	}
	A=-A;
	if (minval(A) != -9) {
		std::cout << "minval test failed(-9)\n";
		return 1;
	}

	A=reshape(linspace(1,9,9),3,3);
	Array<bool,2> B(3,3);
	B=true;
	if (minval_with_mask(A,B) != 1) {
		std::cout << "minval with mask test failed (all masked)\n";
		return 1;
	}

	B=(A>=5);
	if (minval_with_mask(A,B) != 5) {
		std::cout << "minval with mask test failed (some masked)\n";
		return 1;
	}

	std::cout << "minval test passed\n\n";

}
