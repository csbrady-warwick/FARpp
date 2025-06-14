#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing reduce in direction with mask and identity " << argv[0] << "\n";

    //Reduction by sum
    Array<int,2> a = reshape(FortranLiteral(1,2,3,4,5,6),3,2);
    auto result = reduce_with_mask_and_identity(a,[](const int &x, const int &y){return x+y;},2,a>3,-1);

    if (any(result!=literal(4,5,6))){
        std::cout << "reduce with sum failed (false positive)\n";
        return -1;
    }

    result = reduce_with_mask_and_identity(a,[](const int &x, const int &y){return x+y;},1,a>3,-1);
    if (any(result!=literal(-1,15))){
        std::cout << "reduce with sum failed (false negative)\n";
        return -1;
    }

    std::cout << "All tests passed\n\n";
}
