#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main(){

    std::cout << "Testing max function\n";

    if (max(2,3) != 3) {
        std::cout << "Error 2 parameter integer max \n";
        return -1;
    }

    if (max(2.0,4.0,3.0,5.0) != 5.0) {
        std::cout << "Error 4 parameter double max \n";
        return -1;
    }

    if (max(1.0f,2.0f,6.0f,5.0f,4.0f,3.0f) != 6.0f) {
        std::cout << "Error 6 parameter float max \n";
        return -1;
    }

    Array<int,2> A(NX,NY), B(NX,NY);
    A = reshape(linspace(1,NX*NY,NX*NY),NX,NY);
    B = max(A,2);
    for (int j=1; j<=NY; j++) {
        for (int i=1; i<=NX; i++) {
            if (B(i,j) != std::max(A(i,j),2)) {
                std::cout << "Error Array/Value max\n";
                return -1;
            }
        }
    }

    B = A*2;
    if (any(max(B,A) != B)) {
        std::cout << "Error Array/Array max\n";
        return -1;
    }

    std::cout << "max function passed\n\n";
}