#include <iostream>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing reshape with order\n";

    {
        Array<int,2> a = {{1,2},{3,4},{5,6}};
        Array<int,2> b = {{1,3,5},{2,4,6}};
        if (any(reshape_with_order(a,constLiteral(3,2),literal(2,1)) != b)){
            std::cout << "2d rotation failed\n";
            return 1;
        }
    }

    {
        Array<int,3> a = {{{1,2},{3,4},{5,6}},{{7,8},{9,10},{11,12}}};
        Array<int,3> b = reshape_with_order(a,constLiteral(3,2,2),constLiteral(3,2,1));
        Array<int,3> result = {{{1,5,9},{3,7,11}},{{2,6,10},{4,8,12}}};

        if (any(b != result)){
            std::cout << "3d shuffle failed\n";
            return 1;
        }
    }

    {
        Array<int,3> a = reshape(linspace(1,12,12),constLiteral(2,3,2));
        Array<int,2> b = reshape_with_order(a,constLiteral(4,3),constLiteral(2,1));
        Array<int,2> result = reshape(literal(1,4,7,10,2,5,8,11,3,6,9,12),constLiteral(4,3));
        if (any(b != result)){
            std::cout << "3d to 2d with shuffle fail failed\n";
            return 1;
        }
    }


    std::cout << "All tests passed\n";
}
