#include <iostream>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing reduce with mask and identity\n";

    //Reduction by sum
    Array<int,2> a = reshape(literal(1,2,3,4,5,6),3,2);
    Array<bool,2> mask = reshape(literal(true,false,true,false,true,false),3,2);
    auto result = reduce_with_mask_and_identity(a,[](const int &x, const int &y){return x+y;},mask,14);
    if (result != 9) {
        std::cout << "reduce with add failed\n";
        return 1;
    }
    mask = false;
    result = reduce_with_mask_and_identity(a,[](const int &x, const int &y){return x+y;},mask,14);
    if (result != 14) {
        std::cout << "reduce with add failed with no elements\n";
        return 1;
    }

    //Reduction by product
    Array<double,1> b = linspace(1,10,10);
    Array<double,1> mask2 = literal(true,true,true,false,false,true,true,false,false,false);
    auto result2 = reduce_with_mask_and_identity(b,[](const double &x, const double &y){return x*y;},mask2,123.0);
    if (result2 != 252) {
        std::cout << "reduce with multiply failed\n";
        return 1;
    }

    mask2 = false;
    result2 = reduce_with_mask_and_identity(b,[](const double &x, const double &y){return x*y;},mask2,123.0);
    if (result2 != 123.0) {
        std::cout << "reduce with multiply failed with no elements\n";
        return 1;
    }

    std::cout << "All tests passed\n\n";
}