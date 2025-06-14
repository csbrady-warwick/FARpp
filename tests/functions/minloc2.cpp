#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

	std::cout << "Testing minloc with direction " << argv[0] << "\n";

    Array<int,2> A = reshape(linspace(1,9,9),3,3);
	A(1,2)=8;
	A(3,3)=0;

/*
   | 1 | 2 | 3 |
   ------------
 1 |  1|  8|  7|
 2 |  2|  5|  8|
 3 |  3|  6|  0|
*/

	if(any(minloc(A,1)!=literal(1,2,3))){
		std::cout<<"Failed minloc find dim 1\n";
		return -1;
	}

	if(any(minloc(A,2)!=literal(1,1,3))){
		std::cout<<"Failed minloc find dim 2\n";
		return -1;
	}

	Array<bool,2> mask;
	mask.mold(A);
	mask = true;
	mask(3,Range()) = false;
	if (any(minloc_with_mask(A,1,mask)!=literal(1,2,1))){
		std::cout<<"Failed minloc with mask dim 1\n";
		return -1;
	}

	if (any(minloc_with_mask(A,2,mask)!=literal(1,1,defaultLB-1))){
		std::cout<<"Failed minloc with mask dim 2\n";
		return -1;
	}

	mask = false;
	if (any(minloc_with_mask(A,1,mask)!=defaultLB-1)){
		std::cout<<"Failed minloc with empty mask dim 1\n";
		return -1;
	}

	if (any(minloc_with_mask(A,2,mask)!=defaultLB-1)){
		std::cout<<"Failed minloc with empty mask dim 2\n";
		return -1;
	}

	deallocate(A);
	allocate(A,0,0);
	if (any(minloc_with_mask(A,1,mask)!=defaultLB-1)){
		std::cout<<"Failed minloc with empty array dim 1\n";
		return -1;
	}

	if (any(minloc_with_mask(A,2,mask)!=defaultLB-1)){
		std::cout<<"Failed minloc with empty array dim 2\n";
		return -1;
	}

	std::cout << "minloc test passed\n\n";

}
