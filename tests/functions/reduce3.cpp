#include <iostream>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing reduce with identity\n";

    //Reduction by sum
    Array<int,2> a = reshape(literal(1,2,3,4,5,6),3,2);
    auto result = reduce_with_identity(a,[](const int &x, const int &y){return x+y;},14);
    if (result != 21) {
        std::cout << "reduce with add failed\n";
        return 1;
    }
    //Reduction by product
    Array<double,1> b;
    auto result2 = reduce_with_identity(b,[](const double &x, const double &y){return x*y;},123.0);
    if (result2 != 123.0) {
        std::cout << "reduce with multiply failed\n";
        return 1;
    }
    std::cout << "All tests passed\n\n";
}