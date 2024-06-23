#include <iostream>
#include "far.h"

using namespace far;

int main(){

    std::cout << "Testing rank\n";

    {
        int a;
        if (rank(a) != 0){
            std::cout << "Failure in scalar\n";
            return -1;
        }
    }

    {
        Array<double,2> a;
        if (rank(a) != 2){
            std::cout << "Failure in rank 2\n";
            return -1;
        }
    }
    {
        Array<int,3> a;
        if (rank(a) != 3){
            std::cout << "Failure in rank 3\n";
            return -1;
        }
    }
    {
        Array<double,4> a;
        if (rank(a) != 4){
            std::cout << "Failure in rank 4\n";
            return -1;
        }
    }
    {
        Array<int,5> a;
        if (rank(a) != 5){
            std::cout << "Failure in rank 5\n";
            return -1;
        }
    }
    {
        Array<double,6> a;
        if (rank(a) != 6){
            std::cout << "Failure in rank 6\n";
            return -1;
        }
    }
    {
        Array<int,7> a;
        if (rank(a) != 7){
            std::cout << "Failure in rank 7\n";
            return -1;
        }
    }

    std::cout << "All tests passed\n\n";

}