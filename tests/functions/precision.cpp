#include <iostream>
#include "far.h"

using namespace far;

int main(){

    if constexpr(std::numeric_limits<double>::is_iec559){
        std::cout << "Testing precision of IEEE 754 double\n";
        double x = 1.0;
        if (precision(x) != 15){
            std::cout << "Failure in double precision\n";
            return -1;
        }
        Array<double,3> A;
        if (precision(A) != 15){
            std::cout << "Failure in double array precision\n";
            return -1;
        }

        std::complex<double> z = 1.0;
        if (precision(z) != 15){
            std::cout << "Failure in complex double precision\n";
            return -1;
        }
        Array<std::complex<double>,3> B;
        if (precision(B) != 15){
            std::cout << "Failure in complex double array precision\n";
            return -1;
        }
    } else {
        std::cout << "Testing precision of non-IEEE 754 double\n";
        std::cout << "Note that this is a self referential test\n";
        double x = 1.0;
        if (precision(x) != std::numeric_limits<double>::digits10){
            std::cout << "Failure in double precision\n";
            return -1;
        }
        Array<double,3> A;
        if (precision(A) != std::numeric_limits<double>::digits10){
            std::cout << "Failure in double array precision\n";
            return -1;
        }
        std::complex<double> z = 1.0;
        if (precision(z) != std::numeric_limits<double>::digits10){
            std::cout << "Failure in complex double precision\n";
            return -1;
        }
        Array<std::complex<double>,3> B;
        if (precision(B) != std::numeric_limits<double>::digits10){
            std::cout << "Failure in complex double array precision\n";
            return -1;
        }

    }

    if constexpr(std::numeric_limits<float>::is_iec559){
        std::cout << "Testing precision of IEEE 754 float\n";
        float x = 1.0;
        if (precision(x) != 6){
            std::cout << "Failure in float precision\n";
            return -1;
        }
        Array<float,3> A;
        if (precision(A) != 6){
            std::cout << "Failure in float array precision\n";
            return -1;
        }
        std::complex<float> z = 1.0;
        if (precision(z) != 6){
            std::cout << "Failure in complex float precision\n";
            return -1;
        }
        Array<std::complex<float>,3> B; 
        if (precision(B) != 6){
            std::cout << "Failure in complex float array precision\n";
            return -1;
        }
    } else {
        std::cout << "Testing precision of non-IEEE 754 double\n";
        std::cout << "Note that this is a self referential test\n";
        float x = 1.0;
        if (precision(x) != std::numeric_limits<float>::digits10){
            std::cout << "Failure in float precision\n";
            return -1;
        }
        Array<float,3> A;
        if (precision(A) != std::numeric_limits<float>::digits10){
            std::cout << "Failure in float array precision\n";
            return -1;
        }
        std::complex<float> z = 1.0;
        if (precision(z) != std::numeric_limits<float>::digits10){
            std::cout << "Failure in complex float precision\n";
            return -1;
        }
        Array<std::complex<float>,3> B;
        if (precision(B) != std::numeric_limits<float>::digits10){
            std::cout << "Failure in complex float array precision\n";
            return -1;
        }
    }
    std::cout << "All tests passed\n\n";


}