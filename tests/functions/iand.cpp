#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main() {
    std::cout << "Testing iand" << std::endl;

    if (iand(uint8_t(0b1010), uint8_t(0b1100)) != 0b1000) {
        std::cout << "Scalar test failed" << std::endl;
        return -1;
    }

    Array<uint8_t,2> a(NX,NY);
    Array<uint8_t,2> b(NX,NY);
    a = 0b1010;
    b = 0b1100;
    if (any(iand(a, b) != 0b1000)) {
        std::cout << "Array test failed" << std::endl;
        return -1;
    }
    std::cout << "All tests passed\n\n";
    return 0;
}