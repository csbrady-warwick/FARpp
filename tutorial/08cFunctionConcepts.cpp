#include <iostream>
#include "far.h"

template<far::arrayParameter<double,2> P1, far::arrayParameter<double,2> P2>
void func(P1 &param1, const P2 &param2){

  std::cout << param1 + param2 << "\n";

}

int main(){
  far::Array<double,2> Array1 = reshape(far::linspace<double>(0,1,9),3,3);
	far::Array<double,2> Array2 = reshape(far::linspace<double>(1,0,9),3,3);

	//Should count down from 2 to 1 in 0.125 increments
  func(Array1,Array2*2);
}
