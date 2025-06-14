#include <iostream>
#include "far.h"

using namespace far;

#define NX 3
#define NY 3

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing parity function " << argv[0] << "\n";

    Array<bool,2> A(NX,NY);
    A=true;
    if (!all(parity(A,1))) {
        std::cout << "Failure in parity(A,1) with all true elements\n";
        return -1;
    }

    if (!all(parity(A,2))) {
        std::cout << "Failure in parity(A,2) with all true elements\n";
        return -1;
    }

    A(1,2)=false;
    if (any(parity(A,1) != literal(true,false,true))) {
        std::cout << "Failure in parity(A,1) with false element\n";
        return -1;
    }

    if (any(parity(A,2) != literal(false,true,true))) {
        std::cout << "Failure in parity(A,2) with false element\n";
        return -1;
    }

    std::cout << "All tests passed\n\n";

}
