#include <iostream>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing real\n";
    Array<int,2> a = reshape(literal(1,2,3,4,5,6),3,2);
    Array<double,2> b = real(a);
    if (any(b != a)) {
        std::cout << "real failed\n";
        return 1;
    }
    std::cout << "All tests passed\n\n";
}