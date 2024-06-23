#include <iostream>
#include "far.h"

using namespace far;

int main() {
    std::cout << "Testing product\n";
    Array<int,1> a = literal(1,2,3,4);
    if (product(a) != 24) {
        std::cerr << "product failed\n";
        return 1;
    }
    Array<bool,1> mask = literal(true, false, true, true);
    if (product_with_mask(a, mask) != 12) {
        std::cerr << "product with mask failed\n";
        return 1;
    }
    std::cout << "Tests passed\n\n";
}