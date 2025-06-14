#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    {

			std::cout << "Testing Matmul " << argv[0] << "\n";

        Array<float,2> matrix(3,3), matrix2(3,3), reference;
        matrix = reshape(FortranLiteral<float>(1,2,3,4,5,6,7,8,9),3,3);
        matrix2 = reshape(FortranLiteral<float>(9,8,7,6,5,4,3,2,1),3,3);
        reference = reshape(FortranLiteral<float>(90,114,138,54,69,84,18,24,30),3,3);
        if (any(abs(matmul(matrix,matrix2)-reference)>1e-6)){
            std::cout << "matrix matrix multiply failed\n";
            return 1;
        }
    }
    {
        Array<double,2> matrix(3,3);
        Array<double,1> vector(3), reference;
        matrix = reshape(FortranLiteral<double>(1,2,3,4,5,6,7,8,9),3,3);
        vector = FortranLiteral<double>(10,11,12);
        reference = FortranLiteral<double>(138,171,204);
        if (any(abs(matmul(matrix,vector)-reference)>1e-6)){
            std::cout << "matrix vector multiply failed\n";
            return 1;
        }
    }
    {
        Array<double,2> matrix(5,3), matrix2(3,5), reference;
        matrix = reshape(FortranArray<float,1>(linspace<double>(1,15,15)),5,3);
        matrix2 = reshape(FortranArray<float,1>(linspace<double>(1,15,15)),3,5);
        reference = reshape(FortranLiteral<double>(46, 52, 58, 64, 70, 100, 115, 130, 145, 160, 154, 178, 202, 226, 250, 208, 241, 274, 307, 340, 262, 304, 346, 388, 430),5,5);
        if (any(abs(matmul(matrix,matrix2)-reference)>1e-6)){
            std::cout << "Non square matrix matrix multiply failed\n";
            return 1;
        }
    }
    std::cout << "All tests passed \n\n";
}
