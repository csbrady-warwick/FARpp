#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
		std::cout << "Testing sngl " << argv[0] << "\n";

    Array<int,2> A(10,10);
    A=14;
    if (!std::is_same_v<kind<decltype(sngl(A))>,float>){
        std::cout << "Error in type" << std::endl;
        return -1;
    }
    Array<float,2> B = sngl(A);
    if (any(B!=14.0)){
        std::cout << "Error in sngl function" << std::endl;
        return -1;
    }
    std::cout << "Tests passed\n\n";
}
