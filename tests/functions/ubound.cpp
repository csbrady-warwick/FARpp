#include <iostream>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing ubound\n";
    {
        Array<int,1> a(10);
        #ifdef RANK1_INQUIRY_IS_VALUE
        auto result = ubound(a);
        #else
        auto result = ubound(a)(defaultLB);
        #endif
        if (result != 10){
            std::cout << "Failure, rank 1\n";
            std::cout << "Error: lbound(a) != defaultLB\n";
            return -1;
        }
    }
    
    {
        Array<double,2> a(10,10);
        if (!all(ubound(a) == 10)){
            std::cout << "Failure, rank 2\n";
            std::cout << "Error: lbound(a) != defaultLB\n";
            return -1;
        }
    }
    {
        Array<int,1> a(Range(-4,5));
        #ifdef RANK1_INQUIRY_IS_VALUE
        auto result = ubound(a);
        #else
        auto result = ubound(a)(defaultLB);
        #endif
        if (result != 5){
            std::cout << "Failure, rank 1 with specified lower bounds\n";
            std::cout << "Error: lbound(a) != -4\n";
            return -1;
        } 
    }
    {
        Array<double,2> a(Range(-2,7),Range(-5,4));
        if (all((ubound(a)) != literal(7,4))){
            std::cout << "Failure, rank 2 with specified lower bounds\n";
            std::cout << "Error: lbound(a) != [-2,-5]\n";
            return -1;
        }
    }

    std::cout << "Tests passed\n";
}
