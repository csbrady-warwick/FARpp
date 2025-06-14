#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing transfer with size " << argv[0] << "\n";
    auto c = transfer(literal(1.0,2.0,3.0),std::complex<double>(0.0,0.0),1);
    if (!all(c==std::complex<double>(1.0,2.0))){
        std::cout << "Error: transfer(literal(1.0,2.0,3.0),literal<std::complex<double>>(0.0,0.0),1) doesn't match\n";
        return -1;
    }

    std::cout << "All tests passed\n";

}
