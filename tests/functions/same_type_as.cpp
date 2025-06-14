#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing same_type_as " << argv[0] << "\n";
    Array<int,1> a(10);
    Array<int,1> b(10);
    Array<int,2> c(10,10);
    Array<double,1> d(10);

    if (!same_type_as(a,b)){
        std::cout << "Failure checking int array to int array (false negative)\n";
        return -1;
    }

    if (same_type_as(a,c)){
        std::cout << "Failure checking int rank 1 array to int rank 2 array (false positive)\n";
        return -1;
    }

    if (same_type_as(a,d)){
        std::cout << "Failure checking int array to double array (false positive)\n";
        return -1;
    }

    std::cout << "All tests passed\n";

}
