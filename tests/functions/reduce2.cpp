#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing reduce with mask " << argv[0] << "\n";

    //Reduction by sum
    Array<int,2> a = reshape(literal(1,2,3,4,5,6),3,2);
    Array<bool,2> mask = reshape(literal(true,false,true,false,true,false),3,2);
    auto result = reduce_with_mask(a,[](const int &x, const int &y){return x+y;},mask);
    if (result != 9) {
        std::cout << "reduce with add failed\n";
        return 1;
    }
    //Reduction by product
    Array<double,1> b = linspace(1,10,10);
    Array<double,1> mask2 = literal(true,true,true,false,false,true,true,false,false,false);
    auto result2 = reduce_with_mask(b,[](const double &x, const double &y){return x*y;},mask2);
    if (result2 != 252) {
        std::cout << "reduce with multiply failed\n";
        return 1;
    }
    std::cout << "All tests passed\n\n";
}
