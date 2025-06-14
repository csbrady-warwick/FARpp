#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "1D summation with full reduction " << argv[0] << "\n";
    Array<int,1> a = linspace(1,5,5);
    if (sum(a)!=15){
        std::cout << "Failure 1D summation without rank\n";
        return -1;
    }

    Array<double,2> b = reshape(linspace(1,9,9),3,3);
    if (sum(b)!=45){
        std::cout << "Failure 2D summation without rank\n";
        return -1;
    }

    Array<bool,2> mask = b<=5;
    if (sum_with_mask(b,mask)!=15){
        std::cout << "Failure 2D summation with mask\n";
        return -1;
    }
    std::cout << "All tests passed\n\n";
}
