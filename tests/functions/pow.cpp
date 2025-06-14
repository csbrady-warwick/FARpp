#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing pow " << argv[0] << "\n";
    Array<int,1> a = literal(1,2,3,4);
    if (any(pow(a, 2) != literal(1, 4, 9, 16))) {
        std::cerr << "Integer power failed\n";
        return 1;
    }

    Array<double,2> b = reshape(literal(1.0,1.5,2.0,2.5), 2, 2);
    if (any(pow(b, 2) != reshape(literal(1.0, 2.25, 4.0, 6.25),2,2))) {
        std::cerr << "double pow failed\n";
        return 1;
    }
    std::cout << "Tests passed\n\n";
}
