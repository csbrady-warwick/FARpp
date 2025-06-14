#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing reduce in direction with identity " << argv[0] << "\n";

    //Reduction by sum
    Array<int,2> a = reshape(FortranLiteral(1,2,3,4,5,6),3,2);
    auto result = reduce_with_identity(a,[](const int &x, const int &y){return x+y;},2,14);

    if (any(result!=literal(5,7,9))){
        std::cout << "reduce with sum failed\n";
        return -1;
    }

    deallocate(a);
    allocate(a,0,0);
    result = reduce_with_identity(a,[](const int &x, const int &y){return x+y;},2,14);
    if (result.getSize() != 0) {
        std::cout << "zero size reduce with sum failed\n";
        return -1;
    }

    std::cout << "All tests passed\n\n";
}
