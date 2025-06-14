#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing out_of_range " << argv[0] << "\n";

    Array<int,1> A = ones<int>(10);
    if (any(out_of_range(A,1))){
        std::cout << "Failure false positive out_of_range(1 to int)\n";
        return -1;
    }

    A=255;
    if (any(out_of_range(A,uint8_t(1)))){
        std::cout << "Failure false positive out_of_range(255 to uint8_t)\n";
        return -1;
    }

    A = 256;
    if (!all(out_of_range(A,uint8_t(1)))){
        std::cout << "Failure false negative out_of_range(256 to uint8_t)\n";
        return -1;
    }

    if (any(out_of_range(A,1.0))){
        std::cout << "Failure false positive out_of_range(256 to double)\n";
        return -1;
    }

    Array<float,2> B = ones<float>(10,10);
    if (any(out_of_range(B,1))){
        std::cout << "Failure false positive out_of_range(1.0 to int)\n";
        return -1;
    }

    B=255.5;
    if (any(out_of_range(B,uint8_t(1)))){
        std::cout << "Failure false positive out_of_range(255.5 to uint8_t without round)\n";
        return -1;
    }

    B=255.5;
    if (any(out_of_range(B,uint8_t(1),false))){
        std::cout << "Failure false positive out_of_range(255.5 to uint8_t with round=false)\n";
        return -1;
    }

    B=255.5;
    if (!all(out_of_range(B,uint8_t(1),true))){
        std::cout << "Failure false positive out_of_range(255.5 to uint8_t with round)\n";
        return -1;
    }

    std::cout << "All tests passed\n";

}
