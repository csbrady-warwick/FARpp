#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing size " << argv[0] << "\n";

    {
        Array<int,1> Arr(10);
        if (size(Arr) != 10){
            std::cout << "Error in size(Array<int,1>) function" << std::endl;
            return -1;
        }
    }
    {
        Array<int,2> Arr(10,10);
        if (size(Arr) != 100){
            std::cout << "Error in size(Array<int,2>) function" << std::endl;
            return -1;
        }
    }
    {
        Array<int,3> Arr(10,10,10);
        if (size(Arr) != 1000){
            std::cout << "Error in size(Array<int,3>) function" << std::endl;
            return -1;
        }
    }
    {
        Array<int,4> Arr(10,10,10,10);
        if (size(Arr) != 10000){
            std::cout << "Error in size(Array<int,4>) function" << std::endl;
            return -1;
        }
    }
    {
        Array<float,1> Arr(10);
        if (size(Arr,1) != 10){
            std::cout << "Error in size(Array<float,1>,1) function" << std::endl;
            return -1;
        }
    }
    {
        Array<float,2> Arr(16,17);
        if (size(Arr,1) != 16){
            std::cout << "Error in size(Array<float,2>,1) function" << std::endl;
            return -1;
        }
        if (size(Arr,2) != 17){
            std::cout << "Error in size(Array<float,2>,2) function" << std::endl;
            return -1;
        }
        if(size(Arr) != 16*17){
            std::cout << "Error in size(Array<float,2>) function" << std::endl;
            return -1;
        }
    }
    {
        Array<float,3> Arr(16,17,18);
        if (size(Arr,1) != 16){
            std::cout << "Error in size(Array<float,3>,1) function" << std::endl;
            return -1;
        }
        if (size(Arr,2) != 17){
            std::cout << "Error in size(Array<float,3>,2) function" << std::endl;
            return -1;
        }
        if (size(Arr,3) != 18){
            std::cout << "Error in size(Array<float,3>,3) function" << std::endl;
            return -1;
        }
        if(size(Arr) != 16*17*18){
            std::cout << "Error in size(Array<float,3>) function" << std::endl;
            return -1;
        }
    }
    {
        Array<float,4> Arr(16,17,18,19);
        if (size(Arr,1) != 16){
            std::cout << "Error in size(Array<float,4>,1) function" << std::endl;
            return -1;
        }
        if (size(Arr,2) != 17){
            std::cout << "Error in size(Array<float,4>,2) function" << std::endl;
            return -1;
        }
        if (size(Arr,3) != 18){
            std::cout << "Error in size(Array<float,4>,3) function" << std::endl;
            return -1;
        }
        if (size(Arr,4) != 19){
            std::cout << "Error in size(Array<float,4>,4) function" << std::endl;
            return -1;
        }
        if(size(Arr) != 16*17*18*19){
            std::cout << "Error in size(Array<float,4>) function" << std::endl;
            return -1;
        }
    }

    std::cout << "Tests passed\n\n";

}
