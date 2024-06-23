#include <iostream>
#define FAR_DEFAULT_BOUNDS_CHECK
#include "far.h"

int main() {

    far::Array<int,1> a(10);
    try{
        a(0) = 1;
    } catch (std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

}