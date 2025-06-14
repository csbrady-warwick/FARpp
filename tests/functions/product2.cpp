#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing product " << argv[0] << "\n";
    Array<int,2> a = reshape(FortranLiteral(1,2,3,4), 2, 2);
    if (any(product(a,1) != literal(2, 12))) {
        std::cerr << "product(a,1) failed\n";
        return 1;
    }
    if (any(product(a,2) != literal(3, 8))) {
        std::cerr << "product(a,2) failed\n";
        return 1;
    }
    Array<bool,2> mask = reshape(FortranLiteral(true, false, true, true), 2, 2);

    if (any(product_with_mask(a, 1, mask) != literal(1, 12))) {
        std::cerr << "product_with_mask(a, mask, 1) failed\n";
        return 1;
    }

    std::cout << "Tests passed\n\n";
}
