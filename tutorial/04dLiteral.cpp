#include <iostream>
#include "far.h"

int main(){
  far::Array<int,1> myArray = far::literal(1,2,2,4);
  std::cout << myArray << "\n";
}
