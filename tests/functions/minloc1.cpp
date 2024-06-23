#include <iostream>
#include "far.h"

using namespace far;

int main(){

	std::cout << "Testing maxloc\n";

    Array<int,2> A = reshape(linspace(1,9,9),3,3);
	A(1,2)=8;
	A(3,3)=1;

	if(any(minloc(A)!=literal(1,1))){
		std::cout<<"Failed minloc find forwards\n";
		return -1;
	}

	if(any(minloc(A,true)!=literal(3,3))){
		std::cout<<"Failed minloc find backwards\n";
		return -1;
	}

	Array<bool,2> mask;
	mask.mold(A);
	mask = true;
	mask(1,1) = false;

	if (any(minloc_with_mask(A,mask)!=literal(3,3))){
		std::cout<<"Failed minloc with mask\n";
		return -1;
	}

	mask = false;
	if (any(minloc_with_mask(A,mask)!=defaultLB-1)){
		std::cout<<"Failed minloc with empty mask\n";
		return -1;
	}

	deallocate(A);
	allocate(A,0,0);
	if (any(minloc(A)!=defaultLB-1)){
		std::cout<<"Failed minloc on empty array\n";
		return -1;
	}

	std::cout << "minloc test passed\n\n";

}
