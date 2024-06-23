#include <iostream>
#include "far.h"

using namespace far;

int main(){

	std::cout << "Testing maxloc with direction\n";

    Array<int,2> A = reshape(linspace(1,9,9),3,3);
	A(1,2)=8;
	A(3,3)=0;

	if(any(maxloc(A,1)!=literal(3,1,2))){
		std::cout<<"Failed maxloc find dim 1\n";
		return -1;
	}

	if(any(maxloc(A,2)!=literal(2,3,2))){
		std::cout<<"Failed maxloc find dim 2\n";
		return -1;
	}

	Array<bool,2> mask;
	mask.mold(A);
	mask = true;
	mask(3,Range()) = false;
	if (any(maxloc_with_mask(A,1,mask)!=literal(2,1,2))){
		std::cout<<"Failed maxloc with mask dim 1\n";
		return -1;
	}

	if (any(maxloc_with_mask(A,2,mask)!=literal(2,3,0))){
		std::cout<<"Failed maxloc with mask dim 2\n";
		return -1;
	}

	mask = false;
	if (any(maxloc_with_mask(A,1,mask)!=defaultLB-1)){
		std::cout<<"Failed maxloc with empty mask dim 1\n";
		return -1;
	}

	if (any(maxloc_with_mask(A,2,mask)!=defaultLB-1)){
		std::cout<<"Failed maxloc with empty mask dim 2\n";
		return -1;
	}

	deallocate(A);
	allocate(A,0,0);
	if (any(maxloc_with_mask(A,1,mask)!=defaultLB-1)){
		std::cout<<"Failed maxloc with empty array dim 1\n";
		return -1;
	}

	if (any(maxloc_with_mask(A,2,mask)!=defaultLB-1)){
		std::cout<<"Failed maxloc with empty array dim 2\n";
		return -1;
	}

	std::cout << "maxloc test passed\n\n";

}
