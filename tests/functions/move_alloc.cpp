#include <iostream>
#include "far.h"

using namespace far;

int main(){
    
        std::cout << "Testing move_alloc\n";
    
        Array<int,1> a = literal(1,2,3,4);
        Array<int,1> c;

        move_alloc(a,c);

        if (allocated(a)){
            std::cout << "Failure 'a' still allocated\n";
            return -1;
        }

        if (!allocated(c)){
            std::cout << "Failure 'c' not allocated\n";
            return -1;
        }

        if (any(c!=literal(1,2,3,4))){
            std::cout << "Failure 'c' has wrong value\n";
            return -1;
        }
    
        std::cout << "All tests passed\n";
}