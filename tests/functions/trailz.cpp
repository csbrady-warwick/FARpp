#include <iostream>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing trailz\n";
    Array<uint8_t,1> A(8);
    A(1)=1;
    for (int i=2;i<=8;i++){
        A(i)=A(i-1)*2;
    }

    if (any(trailz(A)!=linspace(0,7,8))){
        std::cout << "Error: trailz(A) doesn't match\n";
    }

    std::cout << "All tests passed\n";
}