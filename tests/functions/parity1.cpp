#include <iostream>
#include "far.h"

using namespace far;

#define NX 3
#define NY 3

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing parity function " << argv[0] << "\n";

    Array<bool,2> A(NX,NY);
    A=true;
    if (!parity(A)) {
        std::cout << "False positive\n";
        return -1;
    }

    A(1,1)=false;
    if (parity(A)) {
        std::cout << "False negative\n";
        return -1;
    }

    std::cout << "All tests passed\n\n";

}
