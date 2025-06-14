#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing poppar function " << argv[0] << "\n";

    Array<uint8_t,1> A = literal<uint8_t>(0,1,2,3,4,5,6,7);
    Array<uint8_t,1> parity = literal(0,1,1,0,1,0,0,1);
    auto B = toArray(poppar(A));
    for (size_t i=1;i<B.getSize();++i){
        if (B(i)!=parity(i)){
            std::cout << "Failure in popcount at index " << i << "\n";
            return -1;
        }
    }

    std::cout << "All tests passed\n\n";
}
