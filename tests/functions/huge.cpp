#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing huge " << argv[0] << "\n";
    if (huge(float(1.0))!=std::numeric_limits<float>::max()){
        std::cout << "Simple float failure" << std::endl;
        std::cout << "huge failure" << std::endl;
        return -1;
    }

    Array<int,2> A;
    if (huge(A)!=std::numeric_limits<int>::max()){
        std::cout << "Int array failure" << std::endl;
        std::cout << "huge failure" << std::endl;
        return -1;
    }

    std::cout << "All tests passed" << std::endl;

}
