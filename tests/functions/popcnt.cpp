#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing popcount function " << argv[0] << "\n";

    Array<uint8_t,1> A = linspace<uint8_t>(0,255,256);
    auto B = toArray(popcnt(A));
    for (size_t i=1;i<B.getSize();++i){
        if (B(i)!=std::popcount(A(i))){
            std::cout << "Failure in popcount\n";
            return -1;
        }
    }

    std::cout << "All tests passed\n\n";
}
