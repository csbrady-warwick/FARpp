#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing radix " << argv[0] << "\n";
    Array<double,5> a;
    if (radix(a) != std::numeric_limits<double>::radix) {
        std::cerr << "radix failed\n";
        return 1;
    }
    std::cout << "Tests passed\n\n";
}
