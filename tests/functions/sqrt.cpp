#include <iostream>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing sqrt\n";

    Array<float,1> a = sqrt(linspace(1.0f,3.0f,3));
    if (any(abs(a-literal(1.0f,1.41421356f,1.73205081f))>1e-6f)){
        std::cout << "Error: sqrt(linspace(1.0f,3.0f,3)) != [1.0f,1.41421356f,1.73205081f]\n";
        return -1;
    }

    Array<float,2> b = sqrt(reshape(linspace(1.0f,4.0f,4),2,2));
    if (any(abs(b-reshape(literal(1.0f,std::sqrt(2.0f),std::sqrt(3.0f),2.0f),2,2))>1e-6f)){
        std::cout << "Error: sqrt(reshape(linspace(1.0f,4.0f,4),2,2)) != [1.0f,1.41421356f;1.73205081f,2.0f]\n";
        return -1;
    }

    Array<float,3> c = sqrt(reshape(linspace(1.0f,8.0f,8),2,2,2));
    if (any(abs(c-reshape(literal(1.0f,1.41421356f,1.73205081f,2.0f,2.23606798f,2.44948974f,2.64575131f,2.82842712f),2,2,2))>1e-6f)){
        std::cout << "Error: sqrt(reshape(linspace(1.0f,8.0f,8),2,2,2)) != [1.0f,1.41421356f;1.73205081f,2.0f;2.23606798f,2.44948974f;2.64575131f,2.82842712f]\n";
        return -1;
    }

    std::cout << "All tests passed\n";
}