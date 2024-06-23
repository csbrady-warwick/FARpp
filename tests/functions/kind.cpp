#include <iostream>
#include "far.h"

using namespace far;

class demo{

};

int main(){
    std::cout << "Testing kind function\n";
    {
        Array<int,2> Arr;
        if (!std::is_same_v<kind<decltype(Arr)>, int>){
            std::cout << "Error in kind<integer,2> function" << std::endl;
            return -1;
        }
    }
    {
        Array<double,2> Arr;
        if (!std::is_same_v<kind<decltype(Arr)>, double>){
            std::cout << "Error in kind<double,2> function" << std::endl;
            return -1;
        }
    }
    {
        Array<demo,2> Arr;
        if (!std::is_same_v<kind<decltype(Arr)>, demo>){
            std::cout << "Error in kind<demo,2> function" << std::endl;
            return -1;
        }
    }
    {
        Array<int,3> Arr;
        if (!std::is_same_v<kind<decltype(Arr)>, int>){
            std::cout << "Error in kind<integer,3> function" << std::endl;
            return -1;
        }
    }
    {
        Array<double,3> Arr;
        if (!std::is_same_v<kind<decltype(Arr)>, double>){
            std::cout << "Error in kind<double,3> function" << std::endl;
            return -1;
        }
    }
    {
        Array<demo,3> Arr;
        if (!std::is_same_v<kind<decltype(Arr)>, demo>){
            std::cout << "Error in kind<demo,3> function" << std::endl;
            return -1;
        }
    }

    {
        Array<int*,4> Arr;
        if (!std::is_same_v<kind<decltype(Arr)>, int*>){
            std::cout << "Error in kind<int*,4> function" << std::endl;
            return -1;
        }
    }

    {
        Array<std::reference_wrapper<int>,4> Arr;
        if (!std::is_same_v<kind<decltype(Arr)>, std::reference_wrapper<int>>){
            std::cout << "Error in kind<std::reference_wrapper<int>,4> function" << std::endl;
            return -1;
        }
    }

    std::cout << "All tests passed\n";

}