#include <iostream>
#include "far.h"

int main(){
    float f;
    far::random_number(f);
    std::cout << "Random number: " << f << std::endl;

    far::Array<double,2> d(3,3);
    far::random_number(d);
    std::cout << far::gridPrint(d) << std::endl;
}