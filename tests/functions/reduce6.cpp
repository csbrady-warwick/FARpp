#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing reduce in direction with mask " << argv[0] << "\n";

    //Reduction by sum
    Array<int,2> a = reshape(FortranLiteral(1,2,3,4,5,6),3,2);
    auto result = reduce_with_mask(a,[](const int &x, const int &y){return x+y;},2,a>3);

    if (any(result!=literal(4,5,6))){
        std::cout << "reduce with sum failed (false positive)\n";
        return -1;
    }

    try{
        auto result = reduce_with_mask(a,[](const int &x, const int &y){return x+y;},1,a>3);
        std::cout << "reduce with sum failed (false negative)\n";
        return -1;
    } catch (const std::out_of_range &e) {
        //Expected because it is not possible to reduce the array with the given mask
    }


    //Reduction by product
    Array<double,1> b = linspace(1,10,10);
    Array<double,1> mask2 = literal(true,true,true,false,false,true,true,false,false,false);
    auto result2 = reduce_with_mask(b,[](const double &x, const double &y){return x*y;},mask2,1);
    if (result2 != 252) {
        std::cout << "reduce with multiply failed\n";
        return 1;
    }
    std::cout << "All tests passed\n\n";
}
