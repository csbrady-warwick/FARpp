#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing sign " << argv[0] << "\n";
    if (sign(1,1) != 1) {
        std::cout << "Positive integer failed\n";
        return -1;
    }
    if (sign(-1,1) != 1) {
        std::cout << "Negative integer failed\n";
        return -1;
    }
    if (sign(1,-1) != -1) {
        std::cout << "Positive integer with negative sign transfer failed\n";
        return -1;
    }

    if (sign(4,-6)!=-4){
        std::cout << "Positive non-unity integer with negative sign transfer failed\n";
        return -1;
    }

    if (sign(1.0,1.0) != 1) {
        std::cout << "Positive double failed\n";
        return -1;
    }

    if (sign(1.0,0.0) != 1) {
        std::cout << "Positive double with zero sign failed\n";
        return -1;
    }

    if (sign(1.0,-0.0) != -1) {
        std::cout << "Positive double with negative zero sign failed\n";
        return -1;
    }

    Array<double,1> a(3),b(3);
    a=linspace(-3,3,3);
    b=-a;
    if (any(sign(a,b) != literal(3.0,0.0,-3.0))){
        std::cout << "Array sign failed\n";
        return -1;
    }

    std::cout << "All tests passed\n";

}
