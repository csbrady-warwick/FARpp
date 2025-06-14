#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

		std::cout << "Testing range " << argv[0] << "\n";

    if constexpr(std::numeric_limits<double>::is_iec559){
        std::cout << "Testing range of IEEE 754 double\n";
        double x = 1.0;
        if (range(x) != 307){
            std::cout << "Failure in double precision\n";
            return -1;
        }
        Array<double,3> A;
        if (range(A) != 307){
            std::cout << "Failure in double array precision\n";
            return -1;
        }

        std::complex<double> z = 1.0;
        if (range(z) != 307){
            std::cout << "Failure in complex double precision\n";
            return -1;
        }
        Array<std::complex<double>,3> B;
        if (range(B) != 307){
            std::cout << "Failure in complex double array precision\n";
            return -1;
        }
    } else {
        std::cout << "Testing range of non-IEEE 754 double\n";
        std::cout << "Note that this is a self referential test\n";
        double x = 1.0;
        if (range(x) != std::numeric_limits<double>::max_exponent10-1){
            std::cout << "Failure in double precision\n";
            return -1;
        }
        Array<double,3> A;
        if (range(A) != std::numeric_limits<double>::max_exponent10-1){
            std::cout << "Failure in double array precision\n";
            return -1;
        }
        std::complex<double> z = 1.0;
        if (range(z) != std::numeric_limits<double>::max_exponent10-1){
            std::cout << "Failure in complex double precision\n";
            return -1;
        }
        Array<std::complex<double>,3> B;
        if (range(B) != std::numeric_limits<double>::max_exponent10-1){
            std::cout << "Failure in complex double array precision\n";
            return -1;
        }

    }

    if constexpr(std::numeric_limits<float>::is_iec559){
        std::cout << "Testing range of IEEE 754 float\n";
        float x = 1.0;
        if (range(x) != 37){
            std::cout << "Failure in float precision\n";
            return -1;
        }
        Array<float,3> A;
        if (range(A) != 37){
            std::cout << "Failure in float array precision\n";
            return -1;
        }
        std::complex<float> z = 1.0;
        if (range(z) != 37){
            std::cout << "Failure in complex float precision\n";
            return -1;
        }
        Array<std::complex<float>,37> B; 
        if (range(B) != 37){
            std::cout << "Failure in complex float array precision\n";
            return -1;
        }
    } else {
        std::cout << "Testing range of non-IEEE 754 double\n";
        std::cout << "Note that this is a self referential test\n";
        float x = 1.0;
        if (range(x) != std::numeric_limits<float>::max_exponent10-1){
            std::cout << "Failure in float precision\n";
            return -1;
        }
        Array<float,3> A;
        if (range(A) != std::numeric_limits<float>::max_exponent10-1){
            std::cout << "Failure in float array precision\n";
            return -1;
        }
        std::complex<float> z = 1.0;
        if (range(z) != std::numeric_limits<float>::max_exponent10-1){
            std::cout << "Failure in complex float precision\n";
            return -1;
        }
        Array<std::complex<float>,3> B;
        if (range(B) != std::numeric_limits<float>::max_exponent10-1){
            std::cout << "Failure in complex float array precision\n";
            return -1;
        }
    }
    std::cout << "All tests passed\n\n";


}
