#include <iostream>
#include "far.h"

int main(){
  far::Array<int,1> A(far::Range(-1,8));
	A = far::linspace<int>(1,10,10);
	for (int i=far::lbound(A)(1);i<=far::ubound(A)(1);++i){
		std::cout << i << " : " << A(i) << "\n";
	}
}
