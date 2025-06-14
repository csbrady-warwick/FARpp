#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing summation with rank reduction " << argv[0] << "\n";

    Array<int,1> a = linspace(1,5,5);
    if (sum(a,1)!=15){
        std::cout << "Failure 1D summation with rank\n";
        return -1;
    }

    Array<double,2> b = reshape(FortranArray<double,1>(linspace(1,9,9)),3,3);
    if (any(sum(b,1)!=Array<double,1>({6,15,24}))){
        std::cout << "Failure 2D summation with rank=1\n";
        return -1;
    }

    if (any(sum(b,2)!=Array<double,1>({12,15,18}))){
        std::cout << "Failure 2D summation with rank=2\n";
        return -1;
    }

    Array<bool,2> mask = b<=5;
    if (any(sum_with_mask(b,1,mask)!=Array<double,1>({6,9,0}))){
        std::cout << "Failure 2D summation with mask and rank\n";
        return -1;
    }

    if (any(sum_with_mask(b,2,mask)!=Array<double,1>({5,7,3}))){
        std::cout << "Failure 2D summation with mask and rank\n";
        return -1;
    }

    std::cout << "All tests passed\n\n";

}
