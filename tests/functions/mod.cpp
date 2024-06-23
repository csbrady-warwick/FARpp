#include <iostream>
#include "far.h"

using namespace far;

int main(){

    std::cout << "Testing mod\n";

    if (mod(5, 3)!=2){
        std::cout << "Error in mod(5, 3)\n";
        return -1;
    }
    if (mod(-5, 3)!=-2){
        std::cout << "Error in mod(-5, 3)\n";
        return -1;
    }
    if (mod(5, -3)!=2){
        std::cout << "Error in mod(5, -3)\n";
        return -1;
    }
    if (mod(-5, -3)!=-2){
        std::cout << "Error in mod(-5, -3)\n";
        return -1;
    }

    Array<int,1> a = literal(5,-5,5,-5);
    Array<int,1> b = literal(3,3,-3,-3);

    if (any(mod(a,b)!=literal(2,-2,2,-2))){
        std::cout << "Error in mod(a,b)\n";
        return -1;
    }

    std::cout << "All tests passed\n";
}