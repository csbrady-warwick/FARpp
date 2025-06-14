#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing reshape with order " << argv[0] << "\n";

    {
        Array<int,2> a = rowLiteral({{1,3,5},{2,4,6}}); //Create an array with rows 1,3,5 and 2,4,6 in both C and Fortran order
        Array<int,2> b = reshape(literal(1,3,5,2,4,6),constLiteral(3,2)); // Lay the same elements out in natural order
				//Should be the same in both C and Fortran
        if (any(reshape_with_order(a,constLiteral(3,2),literal(2,1)) != b)){
            std::cout << "2d rotation failed\n";
            return 1;
        }
    }

    {
        Array<int,3> a = FortranArray<int,3>({{{1,2},{3,4},{5,6}},{{7,8},{9,10},{11,12}}});
        Array<int,3> b = reshape_with_order(a,constLiteral(3,2,2),constLiteral(3,2,1));
#ifndef FAR_USE_C_INDEX
				Array<int,3> result = rowLiteral({{{1,2},{3,4}},{{5,6},{7,8}},{{9,10},{11,12}}});
#else
				Array<int,3> result = rowLiteral({{{1,7},{3,9}},{{5,11},{2,8}},{{4,10},{6,12}}});
#endif
        if (any(b != result)){
            std::cout << "3d shuffle failed\n";
            return 1;
        }
    }

    {
        Array<int,3> a = reshape(FortranArray<int,1>(linspace(1,12,12)),constLiteral(2,3,2));
        Array<int,2> b = reshape_with_order(a,constLiteral(4,3),constLiteral(2,1));
#ifndef FAR_USE_C_INDEX
				Array<int,2> result = rowLiteral({{1,2,3},{4,5,6},{7,8,9},{10,11,12}});
#else
				Array<int,2> result = rowLiteral({{1,7,3},{9,5,11},{2,8,4},{10,6,12}});
#endif
        if (any(b != result)){
            std::cout << "3d to 2d with shuffle fail failed\n";
            return 1;
        }
    }


    std::cout << "All tests passed\n";
}
