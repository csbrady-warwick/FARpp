#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main(){

    std::cout << "Testing min function\n";

    if (min(2,3) != 2) {
        std::cout << "Error 2 parameter integer min \n";
        return -1;
    }

    if (min(2.0,4.0,3.0,5.0) != 2.0) {
        std::cout << "Error 4 parameter double min \n";
        return -1;
    }

    if (min(6.0f,2.0f,1.0f,5.0f,4.0f,3.0f) != 1.0f) {
        std::cout << "Error 6 parameter float min \n";
        return -1;
    }

    Array<int,2> A(NX,NY), B(NX,NY);
    A = reshape(linspace(1,NX*NY,NX*NY),NX,NY);
    B = min(A,2);
    for (int j=1; j<=NY; j++) {
        for (int i=1; i<=NX; i++) {
            if (B(i,j) != std::min(A(i,j),2)) {
                std::cout << "Error Array/Value max\n";
                return -1;
            }
        }
    }

    B = A*2;
    if (any(min(B,A) != A)) {
        std::cout << "Error Array/Array max\n";
        return -1;
    }

    std::cout << "min function passed\n\n";
}