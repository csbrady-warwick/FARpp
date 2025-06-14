#include <iostream>
#include "far.h"
#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing generate " << argv[0] << "\n";
    Array<double,2> A(NX,NY);
    generate(A,[](){static int i=0;return i++;});
    int index=0;
#ifndef FAR_USE_C_INDEX
    for (int j=1;j<=NY;++j)
        for (int i=1;i<=NX;++i){
#else
    for (int i=1;i<=NX;++i)
        for (int j=1;j<=NY;++j){
#endif
            if (A(i,j)!=index++) {
                std::cout << "Simple double failure\n";
                std::cout << "Array failure\n";
                return -1;
            }
        }
    std::cout << "Tests passed\n\n";    
}
