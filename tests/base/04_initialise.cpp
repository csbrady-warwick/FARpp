#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing initialise " << argv[0] << "\n";

    Array<int,1> A={1,2,3};
    if (A.getRankSize(1)!=3){
        std::cout << "Initialise 1D array failed (wrong size)\n";
        return -1;
    }
    if (A(1)!=1 || A(2)!=2 || A(3)!=3){
        std::cout << "Initialise 1D array failed (wrong values)\n";
        return -1;
    }

    A = std::array<int,4>{4,5,6,7};
    if (A.getRankSize(1)!=4){
        std::cout << "Initialise 1D array from std::array failed (wrong size)\n";
        return -1;
    }

    if (A(1)!=4 || A(2)!=5 || A(3)!=6 || A(4)!=7){
        std::cout << "Initialise 1D array from std::array failed (wrong values)\n";
        return -1;
    }

    Array<int,2> B=FortranArray<int,2>({{1,2,3},{4,5,6}});
    if (B.getRankSize(1)!=3 || B.getRankSize(2)!=2){
        std::cout << "Initialise 2D array failed (wrong size)\n";
        return -1;
    }
    if (B(1,1)!=1 || B(2,1)!=2 || B(3,1)!=3 || B(1,2)!=4 || B(2,2)!=5 || B(3,2)!=6){
        std::cout << "Initialise 2D array failed (wrong values)\n";
        return -1;
    }

    std::cout << "Tests passed\n";

}
