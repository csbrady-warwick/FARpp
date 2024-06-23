#include <iostream>
#include "far.h"

int main(){
  far::Array<int,2> A = far::reshape(far::linspace(1,25,25),5,5);
  far::Array<int,2> B = far::forceArray(A(far::Range(2,4),far::Range(2,4)));
  B=14; //This will not affect A;
  std::cout << far::gridPrint(A) << "\n\n";

  far::Array<int,2> C = far::forcePointer(A(far::Range(2,4),far::Range(2,4)));
  C=14; //This will affect A
  std::cout << far::gridPrint(A) << "\n\n";
}
