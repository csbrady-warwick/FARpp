#include <iostream>
#include "far.h"

int main(){

    far::Array<double,2> arr = far::random_array(5,7);
    std::cout << far::gridPrint(arr) << std::endl;

}