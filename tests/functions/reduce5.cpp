#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing reduce with direction " << argv[0] << "\n";

    //Reduction by sum
    Array<int,2> a = reshape(FortranLiteral(1,2,3,4,5,6),3,2);
    Array<int,1> result = reduce(a,[](const int &x, const int &y){return x+y;},1);
    if (any(result != literal(6,15))) {
        std::cout << "reduce with add failed dim 1\n";
        return 1;
    }

    result = reduce(a,[](const int &x, const int &y){return x+y;},2);
    if (any(result != literal(5,7,9))) {
        std::cout << "reduce with add failed dim 2\n";
        return 1;
    }


    //Reduction by product
    Array<double,1> b = linspace(1,10,10);
    auto result2 = reduce(b,[](const double &x, const double &y){return x*y;},1);
    if (result2 != 3628800) {
        std::cout << "reduce with multiply failed\n";
        return 1;
    }

    std::cout << "All tests passed\n\n";
}
