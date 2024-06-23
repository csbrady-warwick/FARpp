#include <iostream>
#include "far.h"

int main(){
  far::Array<int,2> myArray = far::reshape(far::literal(1,2,2,4),2,2);
  std::cout << myArray << "\n";
}
