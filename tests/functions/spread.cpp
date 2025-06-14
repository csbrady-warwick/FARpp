#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing spread " << argv[0] << "\n";

    Array<int,1> a=linspace(1,3,3);
    Array<int,2> b = spread(a,1,4);
    if (any(shape(b)!=literal(4,3))){
        std::cout << "Error: shape(spread(a,1,4)) != [4,3]\n";
        return -1;
    }
    for (int i=1;i<=4;++i){
        if (any(b(i,Range())!=a)){
            std::cout << "Error: spread(a,1,4)(i,:) != a\n";
            return -1;
        }
    }

    b=spread(a,2,4);
    if (any(shape(b)!=literal(3,4))){
        std::cout << "Error: shape(spread(a,2,4)) != [3,4]\n";
        return -1;
    }
    for (int i=1;i<=4;++i){
        if (any(b(Range(),i)!=a)){
            std::cout << "Error: spread(a,2,4)(:,i) != a\n";
            return -1;
        }
    }

    b = reshape(linspace(1,4,4),2,2);
    Array<int,3> c = spread(b,1,3);
    if (any(shape(c)!=literal(3,2,2))){
        std::cout << "Error: shape(spread(b,1,3)) != [3,2,2]\n";
        return -1;
    }
    for (int i=1;i<=3;++i){
        if (any(c(i,Range(),Range())!=b)){
            std::cout << "Error: spread(b,1,3)(i,:,:) != b\n";
            return -1;
        }
    }

    c = spread(b,2,3);
    if (any(shape(c)!=literal(2,3,2))){
        std::cout << "Error: shape(spread(b,2,3)) != [2,3,2]\n";
        return -1;
    }
    for (int i=1;i<=3;++i){
        if (any(c(Range(),i,Range())!=b)){
            std::cout << "Error: spread(b,2,3)(:,i,:) != b\n";
            return -1;
        }
    }

    c = spread(b,3,3);
    if (any(shape(c)!=literal(2,2,3))){
        std::cout << "Error: shape(spread(b,3,3)) != [2,2,3]\n";
        return -1;
    }
    for (int i=1;i<=3;++i){
        if (any(c(Range(),Range(),i)!=b)){
            std::cout << "Error: spread(b,3,3)(:,:,i) != b\n";
            return -1;
        }
    }

    std::cout << "All tests passed\n";
}
