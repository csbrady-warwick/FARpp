#include <iostream>
#include "far.h"

using namespace far;

int main(){
    
        std::cout << "Testing transpose\n";
        {
            Array<int,2> A = {{1,2},{3,4}};
            Array<int,2> B = {{1,3},{2,4}};
            if (!all(transpose(A)==B)){
                std::cout << "Error: transpose(A) 2x2 doesn't match\n";
                return -1;
            }
        }
        {
            Array<int,2> A = {{1,2,3},{4,5,6}};
            Array<int,2> B = {{1,4},{2,5},{3,6}};
            if (!all(transpose(A)==B)){
                std::cout << "Error: transpose(A) 3x2 doesn't match\n";
                return -1;
            }
        }
    
        std::cout << "All tests passed\n";
}