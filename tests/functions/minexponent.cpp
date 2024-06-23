#include <iostream>
#include "far.h"

using namespace far;

int main(){

    std::cout << "Testing minexponent\n";
    if (minexponent(2.0) != std::numeric_limits<double>::min_exponent) {
        std::cout << "Error double minexponent \n";
        return -1;
    }

    if (minexponent(2.0f) != std::numeric_limits<float>::min_exponent) {
        std::cout << "Error float minexponent \n";
        return -1;
    }

    Array<double,4> A;
    if (minexponent(A) != std::numeric_limits<double>::min_exponent) {
        std::cout << "Error Array minexponent \n";
        return -1;
    }

    std::cout << "minexponent function passed\n\n";
}