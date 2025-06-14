#include <iostream>
#include "far.h"

using namespace far;

struct demo{
    int i;
    char c[3];
};

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing storage_size " << argv[0] << "\n";
    int i;
    if (storage_size(i)!=sizeof(int)*CHAR_BIT){
        std::cout << "Error: storage_size(int) != sizeof(int)\n";
        return -1;
    }
    float f;
    if (storage_size(f)!=sizeof(float)*CHAR_BIT){
        std::cout << "Error: storage_size(float) != sizeof(float)\n";
        return -1;
    }
    double d;
    if (storage_size(d)!=sizeof(double)*CHAR_BIT){
        std::cout << "Error: storage_size(double) != sizeof(double)\n";
        return -1;
    }
    demo x;
    if (storage_size(x)!=sizeof(demo)*CHAR_BIT){
        std::cout << "Error: storage_size(demo) != sizeof(demo)\n";
        return -1;
    }

    std::cout << "All tests passed\n\n";
}
