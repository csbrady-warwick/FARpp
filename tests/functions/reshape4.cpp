#include <iostream>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing reshape with order and pad\n";

    {
        Array<int,2> a = {{1,2},{3,4},{5,6}};
        Array<int,2> b = {{1,3,5,0},{2,4,6,0}};
        if (any(reshape_with_order_and_pad(a,constLiteral(3,2),constLiteral(2,1),0) != b)){
            std::cout << "2d rotation with scalar pad failed\n";
            return 1;
        }
    }

    {
        Array<int,3> a = {{{1,2},{3,4},{5,6}},{{7,8},{9,10},{11,12}}};
        Array<int,3> b = reshape_with_order_and_pad(a,constLiteral(4,2,2),constLiteral(3,2,1),constLiteral(-1,-2,-3,-4));
        Array<int,3> result = {{{1,5,9,-1},{3,7,11,-3}},{{2,6,10,-2},{4,8,12,-4}}};

        if (any(b != result)){
            std::cout << "3d shuffle with vector pad failed\n";
            return 1;
        }
    }

    {
        Array<int,3> a = reshape(linspace(1,12,12),constLiteral(2,3,2));
        Array<int,2> b = reshape_with_order_and_pad(a,constLiteral(4,4),constLiteral(2,1),constLiteral(-1,-2,-3,-4,-5));
        Array<int,2> result = reshape(literal(1,5,9,-1,2,6,10,-2,3,7,11,-3,4,8,12,-4),constLiteral(4,4));
        if (any(b != result)){
            std::cout << "3d to 2d with shuffle and vector pad fail failed\n";
            return 1;
        }
    }


    std::cout << "All tests passed\n";
}