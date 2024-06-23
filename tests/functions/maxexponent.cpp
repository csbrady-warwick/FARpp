#include <iostream>
#include "far.h"

using namespace far;

int main(){

    std::cout << "Testing maxexponent\n";
    if (maxexponent(2.0) != std::numeric_limits<double>::max_exponent) {
        std::cout << "Error double maxexponent \n";
        return -1;
    }

    if (maxexponent(2.0f) != std::numeric_limits<float>::max_exponent) {
        std::cout << "Error float maxexponent \n";
        return -1;
    }

    Array<double,4> A;
    if (maxexponent(A) != std::numeric_limits<double>::max_exponent) {
        std::cout << "Error Array maxexponent \n";
        return -1;
    }

    std::cout << "maxexponent function passed\n\n";
}