#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing unpack " << argv[0] << "\n";
    {
        Array<int,1> src = linspace(1,9,9);
        Array<bool,2> dst(3,3);
        Array<int,2> field(3,3);
        dst=true;

        if (any(unpack(src,dst,field)!=reshape(src,3,3))){
            std::cout << "Error: simple unpack failure\n";
            return -1;
        }

        dst(Range(),2)=false;
        field=-5;
#ifndef FAR_USE_C_INDEX
        if (any(unpack(src,dst,field)!=reshape(literal(1,2,3,-5,-5,-5,4,5,6),3,3))){
            std::cout << "Error: unpack with mask failure\n";
            return -1;
        }
#else
        if (any(unpack(src,dst,field)!=reshape(literal(1,-5,2,3,-5,4,5,-5,6),3,3))){
            std::cout << "Error: unpack with mask failure\n";
            return -1;
        }
#endif
    }

    {
        Array<int,1> src = linspace(1,27,27);
        Array<bool,3> dst(3,3,3);
        Array<int,3> field(3,3,3);
        dst=true;

        if (any(unpack(src,dst,field)!=reshape(src,3,3,3))){
            std::cout << "Error: simple 3dunpack failure\n";
            return -1;
        }
    }

    std::cout << "All tests passed\n";

}
