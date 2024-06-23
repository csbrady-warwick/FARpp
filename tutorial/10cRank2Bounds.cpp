#include <iostream>
#include <iomanip>
#include "far.h"

int main(){
  far::Array<int,2> A(far::Range(-1,1),far::Range(-1,1));
	A = far::reshape(far::linspace(1,9,9),3,3);
	for (int j=far::lbound(A,2);j<=far::ubound(A,2);++j){
		for (int i=far::lbound(A,1);i<=far::ubound(A,1);++i){
			std::cout << std::setw(3) << std::setfill(' ') << i << ", " << std::setw(3) << std::setfill(' ') << j << " : " << A(i,j) << "\n";
		}
	}
}
