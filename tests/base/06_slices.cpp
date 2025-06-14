#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing slices " << argv[0] << "\n";

    Array<int,1> a={1,2,3};

    if (any(a(Range())!=a)){
        std::cout << "Whole 1D range != array\n";
        return -1;
    }

    if (any(a(Range(1,1))!=a(1))){
        std::cout << "Singe element slice != array()\n";
        return -1;
    }

    if (any(a(Range(1,2))!=FortranLiteral<int>(1,2))){
        std::cout << "Error in 1D contiguous slice starting at LB\n";
        return -1;
    }

    if (any(a(Range(2,3))!=FortranLiteral<int>(2,3))){
        std::cout << "Error in 1D contiguous slice ending at UB\n";
        return -1;
    }

    if (any(a(Range(1,3,2))!=FortranLiteral<int>(1,3))){
        std::cout << "Error in 1D non-contiguous slice with stride\n";
        return -1;
    }

    if (any(a(Range(3,1,-1))!=FortranLiteral<int>(3,2,1))){
        std::cout << "Error in 1D non-contiguous slice with negative stride\n";
        return -1;
    }

    if (any(a(Range(3,1,-2))!=FortranLiteral<int>(3,1))){
        std::cout << "Error in 1D non-contiguous slice with negative stride\n";
        return -1;
    }

    Array<int,2> b=FortranArray<int,2>({{1,2,3},{4,5,6},{7,8,9}});

std::cout << gridPrint(b) << "\n";
    if (any(b(Range(),Range())!=b)){
        std::cout << "Whole 2D range != array\n";
        return -1;
    }

    if (any(b(Range(1,2),Range(1,2))!=reshape(FortranLiteral<int>(1,2,4,5),2,2))){
        std::cout << gridPrint(b(Range(1,2),Range(1,2))) << "\n";
        std::cout << "2x2 slice starting at LB,LB wrong\n";
        return -1;
    }

    if (any(b(Range(2,3),Range(1,2))!=reshape(FortranLiteral<int>(2,3,5,6),2,2))){
        std::cout << b(Range(2,3),Range(1,2)) << "\n";
        std::cout << "2x2 slice starting at UB,LB wrong\n";
        return -1;
    }

    if (any(b(Range(1,2), Range(2,3))!=reshape(FortranLiteral<int>(4,5,7,8),2,2))){
        std::cout << "2x2 slice starting at LB,UB wrong\n";
        return -1;
    }

    if (any(b(Range(2,3), Range(2,3))!=reshape(FortranLiteral<int>(5,6,8,9),2,2))){
        std::cout << "2x2 slice starting at UB,UB wrong\n";
        return -1;
    }

    if (any(b(Range(1,3,2), Range(1,3,2))!=reshape(FortranLiteral<int>(1,3,7,9),2,2))){
        std::cout << "2x2 non-contiguous slice with stride wrong\n";
        return -1;
    }

    if (any(b(Range(1,3,2), Range(1,2))!=reshape(FortranLiteral<int>(1,3,4,6),2,2))){
        std::cout << "2x2 non-contiguous slice with stride in one dimension wrong\n";
        return -1;
    }

    if (any(b(Range(3,1,-1), Range(3,1,-1))!=reshape(FortranLiteral<int>(9,8,7,6,5,4,3,2,1),3,3))){
        std::cout << "2x2 non-contiguous slice with negative stride wrong\n";
        return -1;
    }

    if (any(b(Range(3,1,-1), Range(2,3))!=reshape(FortranLiteral<int>(6,5,4,9,8,7),3,2))){
        std::cout << "3x2 non-contiguous slice with negative stride wrong\n";
        return -1;
    }

    {
        auto c = toArray(b(Range(),Range(1,1)));
        if (arrayInfo<decltype(c)>::rank!=2){
            std::cout << "Wrong rank in slice with single element range\n";
            return -1;
        }
        if (any(c!=reshape(FortranLiteral<int>(1,2,3),3,1))){
            std::cout << "Error in 2D single element slice\n";
            return -1;
        }
    }

    {
        auto c = toArray(b(Range(),1));
        if (arrayInfo<decltype(c)>::rank!=1){
            std::cout << "Wrong rank in slice 1D-from-2D with single element range\n";
            return -1;
        }
        if (any(c!=FortranLiteral<int>(1,2,3))){
            std::cout << "Error in 1D-from-2D single element slice\n";
            return -1;
        }
    }


    std::cout << "All tests passed\n\n";
}
