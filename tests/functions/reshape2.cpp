#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing reshape with pad " << argv[0] << "\n";
    
    Array<int,1> a = linspace(1,4,4);
#ifndef FAR_USE_C_INDEX
    Array<int,2> b = {{1,2},{3,4},{5,5}};
#else
    Array<int,2> b = {{1,2,3},{4,5,5}};
#endif
    if (any(reshape_with_pad(a,std::array<int,2>{2,3},5) != b)){
        std::cout << "Reshape with scalar pad failed\n";
        return -1;
    }

    Array<int,1> pad = {5,6};
    if (any(reshape_with_pad(a,std::array<int,2>{2,3},pad) != reshape(linspace(1,6,6),2,3))){
        std::cout << "Reshape with array pad failed\n";
        return -1;
    }

    Array<int,1> pad1 = {5};
    if (any(reshape_with_pad(a,std::array<int,2>{2,3},pad1) != reshape(literal(1,2,3,4,5,5),2,3))){
        std::cout << "Reshape with array pad failed\n";
        return -1;
    } 

    std::cout << "All tests passed\n";

}
