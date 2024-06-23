#include <iostream>
#define FAR_DEFAULT_LB 0
#include "far.h"

int main(){

   far::Array<int,2> a = far::reshape(far::linspace(1,16,16),4,4);
   std::cout << far::gridPrint(a) << "\n";

}