#include <iostream>
#include "far.h"

void func(far::Array<double,1> &A){
  for (int i=far::lbound(A)(1);i<=far::ubound(A)(1);++i){
    std::cout << i << " : " << A(i) << "\n";
  }
}

int main(){
  far::Array<double,1> A(far::Range(-1,8));
	A = far::linspace(1,10,10);
	func(A);
}
