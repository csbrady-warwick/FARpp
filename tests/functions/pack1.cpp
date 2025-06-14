#include <iostream>
#include "far.h"

using namespace far;

#define NX 3
#define NY 4

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing pack " << argv[0] << "\n";
    Array<int,2> A = reshape(linspace<int>(1,NX*NY,NX*NY),NX,NY);
    auto result = pack(A);
    if (result.getSize()!=(NX*NY)){
        std::cout << "Failure size pack\n";
        return -1;
    }
    if (any(result!=linspace<int>(1,NX*NY,NX*NY))){
        std::cout << "Failure content pack\n";
        return -1;
    }

    Array<bool,2> mask(NX,NY);
    mask = true;
    if (any(pack(A,mask)!=linspace<int>(1,NX*NY,NX*NY))){
        std::cout << "Failure content pack with mask\n";
        return -1;
    }
#ifndef FAR_USE_C_INDEX
    for (int j=1;j<=NY;j++){
        for (int i=1;i<=NX;i++){
            mask(i,j) = (i+j*NX)%2;
        }
    }
#else
//This is a bit mucky but it does mean that you can use the same test for C and Fortran ordering
    for (int i=1;i<=NX;i++){
        for (int j=1;j<=NY;j++){
            mask(i,j) = (i*NY+j+1)%2;
        }
    }
#endif

    if (any(pack(A,mask)!=linspace<int>(2,NX*NY,NX*NY/2))){
        std::cout << "Failure content pack with mod(2) mask\n";
        return -1;
    }

    if (any(pack(ones<double>(NX,NX,NX,NX),true)!=1)){
        std::cout << "Failure content pack rank 4 with ones\n";
        return -1;
    }

    std::cout << "All tests passed\n\n";

}
