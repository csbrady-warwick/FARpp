#include <iostream>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing simple reduce\n";

    //Reduction by sum
    Array<int,2> a = reshape(literal(1,2,3,4,5,6),3,2);
    auto result = reduce(a,[](const int &x, const int &y){return x+y;});
    if (result != 21) {
        std::cout << "reduce with add failed\n";
        return 1;
    }

    //Reduction by product
    Array<double,1> b = linspace(1,10,10);
    auto result2 = reduce(b,[](const double &x, const double &y){return x*y;});
    if (result2 != 3628800) {
        std::cout << "reduce with multiply failed\n";
        return 1;
    }

    std::cout << "All tests passed\n\n";
}