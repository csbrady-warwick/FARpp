#include <iostream>
#include "far.h"

using namespace far;

#define NX 3
#define NY 4

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing pack with vector " << argv[0] << "\n";
    Array<int,2> A = reshape(linspace<int>(1,NX*NY,NX*NY),NX,NY);
    Array<bool,2> mask(NX,NY);
    Array<int,1> vector(NX*NY);
    mask=true;
    vector = -1;

    if (any(pack(A,mask,vector)!=linspace<int>(1,NX*NY,NX*NY))){
        std::cout << "Failure content pack\n";
        return -1;
    }

    mask(Range(),toUB(NY/2+1))=false;
    auto result = pack(A,mask,vector);
    if (any(result(Range(1,NX*NY/2))!=pack(A,mask))){
        std::cout << "Failure packed from source\n";
        return -1;
    }

    if (any(result(Range(NX*NY/2+1,NX*NY))!=-1)){
        std::cout << "Failure packed from vector\n";
        return -1;
    }

    std::cout << "All tests passed\n";

}
