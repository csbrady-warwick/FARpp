#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing merge " << argv[0] << "\n";

    if (merge(0,1,true) != 0) {
        std::cout << "scalar merge test failed\n";
        return -1;
    }

    if (merge(0,1,false) != 1) {
        std::cout << "scalar merge test failed\n";
        return -1;
    }

    Array<int,2> A = reshape(linspace(1,9,9),3,3);
    Array<int,2> B = -reshape(linspace(1,9,9),3,3);
    Array<bool,2> mask(3,3);
    mask = A<=5;
    if (any(merge(A,B,mask) != reshape(literal(1,2,3,4,5,-6,-7,-8,-9),3,3))) {
        std::cout << "array merge test failed\n";
        return -1;
    }

    std::cout << "merge test passed\n\n";

}
