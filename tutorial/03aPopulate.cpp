#include <iostream>
#include "far.h"

int main(){
  far::Array<int,2> myArray(2,2);
  for (int j=1;j<=2;++j){
    for (int i=1;i<=2;++i){
      myArray(i,j)=i*j;
    }
  }
  std::cout << myArray << "\n";
}
