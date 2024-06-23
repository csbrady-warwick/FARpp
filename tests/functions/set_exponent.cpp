#include <iostream>
#include "far.h"
#include "compare.h"

using namespace far;

int main(){
    std::cout << "Test set_exponent\n";

    if (softCompare(set_exponent(3.0,1),1.5)){
        std::cout << "Failure\n";
        return -1;
    }

    std::cout << "All tests passed\n";

}