#include <iostream>
#include "far.h"

void func(far::Array<double,2> const &param1, far::Array<double,2> const &param2){

  std::cout << param1 + param2 << "\n";

}

int main(){
  far::Array<double,2> Array1 = reshape(far::linspace<double>(0,1,9),3,3);
	far::Array<double,2> Array2 = reshape(far::linspace<double>(1,0,9),3,3);

	//Should count down from 2 to 1 in 0.125 increments
  func(Array1,Array2*2);
}
