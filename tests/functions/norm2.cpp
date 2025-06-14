#include <iostream>
#include "far.h"
#include "compare.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing norm2 " << argv[0] << "\n";

    Array<float,1> A = literal<float>(3,4);
    if (softCompare(norm2(A),5.0f)){
        std::cout << "Failure norm2\n";
        return -1;
    }

    Array<double,2> B(2,2);
    B=4.0;
    if (softCompare(norm2(B),8.0)){
        std::cout << "Failure norm2 whole array\n";
        return -1;
    }

    Array<double,1> result;
    B = FortranArray<double,2>({{3,4},{3,4}});
    result = norm2(B,1);
    for (int i=1;i<=2;++i){
        if (softCompare(result(i),5.0)){
            std::cout << "Failure norm2 array dim 1\n";
            return -1;
        }
    }

    B= FortranArray<double,2>({{3,3},{4,4}});
    result = norm2(B,2);
    for (int i=1;i<=2;++i){
        if (softCompare(result(i),5.0)){
            std::cout << "Failure norm2 array dim 2\n";
            return -1;
        }
    }


    std::cout << "All tests passed\n";

}
