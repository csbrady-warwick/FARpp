#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

	std::cout << "Testing maxval with direction " << argv[0] << "\n";

    Array<int,2> A = reshape(FortranLinspace(1,9,9),3,3);

	if (any(maxval(A,1) != literal(3,6,9))) {
		std::cout << "maxval test (sum axis 1) failed\n";
		return 1;
	}

	if (any(maxval(A,2) != literal(7,8,9))) {
		std::cout << "maxval test (sum axis 2) failed\n";
		return 1;
	}

	Array<bool,2> mask(3,3);
	mask = true;

	if (any(maxval_with_mask(A,1,mask) != literal(3,6,9))) {
		std::cout << "maxval with mask test (sum axis 1) failed\n";
		return 1;
	}

	if (any(maxval_with_mask(A,2,mask) != literal(7,8,9))) {
		std::cout << "maxval with mask test (sum axis 2) failed\n";
		return 1;
	}

	mask(3,Range()) = false;
	if (any(maxval_with_mask(A,1,mask) != literal(2,5,8))) {
		std::cout << "maxval with mask test (sum axis 2) failed\n";
		return 1;
	}

	mask = true;

	mask(Range(),3) = false;
	if (any(maxval_with_mask(A,1,mask) != literal(3,6,std::numeric_limits<int>::min()))) {
		std::cout << "maxval with mask test (sum axis 1) failed\n";
		return 1;
	}

	std::cout << "maxval test passed\n\n";

}
