#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing reshape with order and pad " << argv[0] << "\n";

    {
        Array<int,2> a = columnLiteral({{1,2},{3,4},{5,6}});
#ifndef FAR_USE_C_INDEX
        Array<int,2> b = columnLiteral({{1,3,5,0},{2,4,6,0}});
#else
        Array<int,2> b = rowLiteral({{1,3},{5,2},{4,6},{0,0}});
#endif
        if (any(reshape_with_order_and_pad(a,constLiteral(3,2),constLiteral(2,1),0) != b)){
            std::cout << "2d rotation with scalar pad failed\n";
            return 1;
        }
    }

    {
        Array<int,3> a = columnLiteral({{{1,2},{3,4},{5,6}},{{7,8},{9,10},{11,12}}});
        Array<int,3> b = reshape_with_order_and_pad(a,constLiteral(4,2,2),constLiteral(3,2,1),constLiteral(-1,-2,-3,-4));
#ifndef FAR_USE_C_INDEX
        Array<int,3> result = columnLiteral({{{1,5,9,-1},{3,7,11,-3}},{{2,6,10,-2},{4,8,12,-4}}});
#else
        Array<int,3> result = rowLiteral({{{1,7},{3,9}},{{5,11},{2,8}},{{4,10},{6,12}},{{-1,-2},{-3,-4}}});
#endif
        if (any(b != result)){
            std::cout << "3d shuffle with vector pad failed\n";
            return 1;
        }
    }

    {
				Array<int,3> a = columnLiteral({{{1,2},{3,4},{5,6}},{{7,8},{9,10},{11,12}}});
        Array<int,2> b = reshape_with_order_and_pad(a,constLiteral(4,4),constLiteral(2,1),constLiteral(-1,-2,-3,-4,-5));
#ifndef FAR_USE_C_INDEX
				Array<int,2> result = columnLiteral({{1,5,9,-1},{2,6,10,-2},{3,7,11,-3},{4,8,12,-4}});
#else
        Array<int,2> result = rowLiteral({{1,7,3,9},{5,11,2,8},{4,10,6,12},{-1,-2,-3,-4}});
#endif
        if (any(b != result)){
            std::cout << "3d to 2d with shuffle and vector pad fail failed\n";
            return 1;
        }
    }

    std::cout << "All tests passed\n";
}
