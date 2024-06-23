#include <iostream>
#include "far.h"

using namespace far;

int main(){

	std::cout << "Testing maxloc\n";

    Array<int,2> A = reshape(linspace(1,9,9),3,3);
	A(1,2)=8;
	A(3,3)=0;

	if(any(maxloc(A)!=literal(1,2))){
		std::cout<<"Failed maxloc find forwards\n";
		return -1;
	}

	if(any(maxloc(A,true)!=literal(2,3))){
		std::cout<<"Failed maxloc find backwards\n";
		return -1;
	}

	Array<bool,2> mask;
	mask.mold(A);
	mask = true;
	mask(1,2) = false;

	if (any(maxloc_with_mask(A,mask)!=literal(2,3))){
		std::cout<<"Failed maxloc with mask\n";
		return -1;
	}

	mask = false;
	if (any(maxloc_with_mask(A,mask)!=defaultLB-1)){
		std::cout<<"Failed maxloc with empty mask\n";
		return -1;
	}

	deallocate(A);
	allocate(A,0,0);
	if (any(maxloc(A)!=defaultLB-1)){
		std::cout<<"Failed maxloc on empty array\n";
		return -1;
	}

	std::cout << "maxloc test passed\n\n";

}
