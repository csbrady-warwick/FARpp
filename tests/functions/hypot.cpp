#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 4

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing hypot " << argv[0] << "\n";
    if (softCompare(hypot(3.0,4.0),5.0)){
        std::cout << "scalar failure\n";
        std::cout << "hypot failure\n";
        return -1;
    }

    Array<float,2> A(NX,NY), B(NX,NY), C;
    A=3.0;
    B=4.0;
    C = hypot(A,B);
    for (int i=1; i<=NX; i++){
        for (int j=1; j<=NY; j++){
            if (softCompare(C(i,j),5.0)){
                std::cout << "array failure at " << i << " " << j << "\n";
                std::cout << "hypot failure" << "\n";
                return -1;
            }
        }
    }

    std::cout << "All tests passed \n";

}
