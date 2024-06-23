#include <iostream>
#include "far.h"

using namespace far;

int main(){

    std::cout << "Testing shape\n";

    {
        if (shape(3).getSize() != 0){
            std::cout << "Failure simple scalar shape\n";
            return -1;
        }
    }

    {
        Array<int,2> A(3,7);
        if (any(shape(A) != literal(3,7))){
            std::cout << "Failure simple 2d shape\n";
            return -1;
        }
    }

    {
        Array<int,5> A(3,7,2,1,5);
        if (any(shape(A) != literal(3,7,2,1,5))){
            std::cout << "Failure simple 5d shape\n";
            return -1;
        }
    }

    {
        Array<int,2> A(Range(3,7),Range(-4,8));
        if (any(shape(A) != literal(5,13))){
            std::cout << "Failure range 2d shape\n";
            return -1;
        }
    }

    {
        Array<int,2> A(3,4);
        auto a = toArray(shape<uint8_t>(A));
        if constexpr (!std::is_same_v<typename arrayInfo<decltype(a)>::type,uint8_t>){
            std::cout << "Failure shape type\n";
            return -1;
        }
    }

    std::cout << "All tests passed\n";
}
