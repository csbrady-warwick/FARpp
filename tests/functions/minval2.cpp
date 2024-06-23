#include <iostream>
#include "far.h"

using namespace far;

int main(){

	std::cout << "Testing minval with direction\n";

    Array<int,2> A = reshape(linspace(1,9,9),3,3);

	if (any(minval(A,1) != literal(1,4,7))) {
		std::cout << "minval test (sum axis 1) failed\n";
		return 1;
	}

	if (any(minval(A,2) != literal(1,2,3))) {
		std::cout << "minval test (sum axis 2) failed\n";
		return 1;
	}

	Array<bool,2> mask(3,3);
	mask = true;

	if (any(minval_with_mask(A,1,mask) != literal(1,4,7))) {
		std::cout << "minval with all active mask test (sum axis 1) failed\n";
		return 1;
	}

	if (any(minval_with_mask(A,2,mask) != literal(1,2,3))) {
		std::cout << "minval with all active mask test (sum axis 2) failed\n";
		return 1;
	}

	mask(1,Range()) = false;
	if (any(minval_with_mask(A,1,mask) != literal(2,5,8))) {
		std::cout << "minval with partial mask test (sum axis 1) failed\n";
		return 1;
	}

	mask = true;

	mask(Range(),1) = false;
	if (any(minval_with_mask(A,1,mask) != literal(std::numeric_limits<int>::min(),4,7))) {
		std::cout << "maxval with partial mask test (sum axis 1) failed\n";
		return 1;
	}

	std::cout << "minval test passed\n\n";

}
