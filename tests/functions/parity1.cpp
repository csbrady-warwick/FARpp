#include <iostream>
#include "far.h"

using namespace far;

#define NX 3
#define NY 3

int main(){
    std::cout << "Testing parity function\n";

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