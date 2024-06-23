#include <iostream>
#include <iomanip>
#include "far.h"

using namespace far;

int main(){

    if constexpr(std::numeric_limits<double>::is_iec559){
        std::cout << "Testing tiny for IEEE 754 double\n";
        double x = 1.0;
        if (tiny(x) != 2.2250738585072014e-308){
            std::cout << "Failure in double precision\n";
            return -1;
        }
        Array<double,3> A;
        if (tiny(A) != 2.2250738585072014e-308){
            std::cout << "Failure in double array precision\n";
            return -1;
        }
    } else {
        std::cout << "Testing range of non-IEEE 754 double\n";
        std::cout << "Note that this is a self referential test\n";
        double x = 1.0;
        if (tiny(x) != std::numeric_limits<double>::min()){
            std::cout << "Failure in double precision\n";
            return -1;
        }
        Array<double,3> A;
        if (tiny(A) != std::numeric_limits<double>::min()){
            std::cout << "Failure in double array precision\n";
            return -1;
        }
    }

    if constexpr(std::numeric_limits<float>::is_iec559){
        std::cout << "Testing range of IEEE 754 float\n";
        float x = 1.0;
        if (tiny(x) != 1.17549435082228750796873653722224567781866556e-38){
            std::cout << "Failure in float precision\n";
            return -1;
        }
        Array<float,3> A;
        if (tiny(A) != 1.17549435082228750796873653722224567781866556e-38){
            std::cout << "Failure in float array precision\n";
            return -1;
        }
    } else {
        std::cout << "Testing range of non-IEEE 754 double\n";
        std::cout << "Note that this is a self referential test\n";
        float x = 1.0;
        if (tiny(x) != std::numeric_limits<float>::min()){
            std::cout << "Failure in float precision\n";
            return -1;
        }
        Array<float,3> A;
        if (tiny(A) != std::numeric_limits<float>::min()){
            std::cout << "Failure in float array precision\n";
            return -1;
        }
    }
    std::cout << "All tests passed\n\n";


}