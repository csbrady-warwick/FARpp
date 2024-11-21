#include <iostream>
#include "far.h"

int main(){
  far::Array<int,2> myArray(3,3);
  for (int j=1;j<=3;++j){
    for (int i=1;i<=3;++i){
      myArray(i,j)=i*j;
    }
  }
	std::cout << "Array from FAR++ is \n";
  std::cout << far::gridPrint(myArray) << "\n\n";

#ifdef FAR_CPP2023
//std::mdspan is a built in C++23 way of viewing memory as a multidimensional array
	std::cout << "Array from FAR++ viewed as a std::mdspan is \n";
	auto b = far::make_mdspan(myArray);
	for (int j=0;j<b.extent(1);++j)
		for (int i=0;i<b.extent(0);++i){
			std::cout << "{" << i << ", " << j << "} =  ";
			std::cout << b[i,j] << "\n";
		}
#else
		std::cout << "This example requires that the test be compiled with C++23 support\n";
#endif
}
