#include <iostream>
#include "far.h"

int main(){
  {
    far::Array<int,1> myArray = {1,2,3};
    std::cout << myArray << "\n";
  }
  {
    far::Array<int,2> myArray = {{1,2,3},{4,5,6}};
    std::cout << myArray << "\n";
  }
  {
    far::Array<int,3> myArray = {{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
    std::cout << myArray << "\n";
  }
}
