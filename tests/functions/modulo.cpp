#include <iostream>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing modulo\n";

    if (modulo(5, 3)!=2){
        std::cout << "Error in modulo(5, 3)\n";
        return -1;
    }
    if (modulo(-5, 3)!=1){
        std::cout << "Error in modulo(-5, 3)\n";
        return -1;
    }
    if (modulo(5, -3)!=-1){
        std::cout << "Error in modulo(5, -3)\n";
        return -1;
    }
    if (modulo(-5, -3)!=-2){
        std::cout << "Error in modulo(-5, -3)\n";
        return -1;
    }

    Array<int,1> a = literal(5,-5,5,-5);
    Array<int,1> b = literal(3,3,-3,-3);

    if (any(modulo(a,b)!=literal(2,1,-1,-2))){
        std::cout << "Error in modulo(a,b)\n";
        return -1;
    }

    std::cout << "All tests passed\n";
}