#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

    std::cout << "Testing where and where_elsewhere " << argv[0] << "\n";
    Array<int,2> A= reshape(linspace(-5,3,9),3,3);
    Array<int,2> B;
    B.mold(A);
    B=1;
    where([](int&src, FAR_UNUSED int&dest){return src<0;},[](FAR_UNUSED int &src, int&dest){dest=0;},A,B);
    if (any(B!=reshape(literal(0,0,0,0,0,1,1,1,1),3,3))){
        std::cout << "Error in where" << std::endl;
        return -1;
    }

    B=-100;
    where_elsewhere([](int&src, FAR_UNUSED int&dest){return src<-1;},[](FAR_UNUSED int &src, int&dest){dest=-10;}, [](int&src, int&dest){dest=src;},A,B);
    if (any(B!=reshape(literal(-10,-10,-10,-10,-1,0,1,2,3),3,3))){
        std::cout << "Error in where_elsewhere" << std::endl;
        return -1;
    }
    std::cout << "All tests passed" << std::endl;
}
