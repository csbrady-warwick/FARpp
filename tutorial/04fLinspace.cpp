#include <iostream>
#include "far.h"

int main(){
  far::Array<int,1> myArray = far::linspace<int>(1,10,10);
  std::cout << myArray << "\n";
}
