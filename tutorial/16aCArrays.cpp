#include <iostream>
#define FAR_USE_C_INDEX
#include "far.h"

int main(){

   far::Array<int,2> a(3,3);

    std::cout << "Delta in x is " << &a(2,1) - &a(1,1) << std::endl;
    std::cout << "Delta in y is " << &a(1,2) - &a(1,1) << std::endl;

}