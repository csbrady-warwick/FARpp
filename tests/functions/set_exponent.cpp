#include <iostream>
#include "far.h"
#include "compare.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Test set_exponent " << argv[0] << "\n";

    if (softCompare(set_exponent(3.0,1),1.5)){
        std::cout << "Failure\n";
        return -1;
    }

    std::cout << "All tests passed\n";

}
