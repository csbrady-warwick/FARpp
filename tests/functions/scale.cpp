#include <iostream>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing scale\n";

    Array<double,1> val = ones(4);
    Array<int,1> scaleval = linspace(0,3,4);

    if (any(scale(val, scaleval) != literal(1,2,4,8))){
        std::cout << "Failure scaling ones array\n";
        return -1;
    }

    std::cout << "All tests passed\n";
}