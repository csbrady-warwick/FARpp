#include <iostream>
#include "far.h"
#define NX 3
#define NY 3

using namespace far;

int main(){
    std::cout << "Testing iota\n";
    Array<double,2> A(NX,NY);
    iota(A,0);
    int index=0;
    for (int j=1;j<=NY;++j)
        for (int i=1;i<=NX;++i){
            if (A(i,j)!=index++) {
                std::cout << "Simple double failure\n";
                std::cout << "Array failure\n";
                return -1;
            }
        }
    std::cout << "Tests passed\n\n";    
}