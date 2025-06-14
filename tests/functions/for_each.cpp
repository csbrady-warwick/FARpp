#include <iostream>
#include "far.h"
#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing for_each " << argv[0] << "\n";
    Array<double,2> A(NX,NY);
    A=1.5;
    for_each(A,[](double &a){a*=2;});
    for (int j=1;j<=NY;++j)
        for (int i=1;i<=NX;++i){
            if (A(i,j)!=3) {
                std::cout << "Simple double failure\n";
                std::cout << "Array failure\n";
                return -1;
            }
        }

    A=1;
    int i=0;
    for_each(A,[&i](double &a){a+=i++;});
    double results[NX*NY];
    for (int i = 0; i<NX*NY; ++i) {
        results[i]=1+i;
    }
#ifndef FAR_USE_C_INDEX
    for (int j=1;j<=NY;++j)
        for (int i=1;i<=NX;++i){
            if (A(i,j)!=results[(j-1)*NX+i-1]) {
                std::cout << "Failure with lambda capture\n";
                std::cout << "Array failure\n";
                return -1;
            }
        }
#else
    for (int i=1;i<=NX;++i)
        for (int j=1;j<=NY;++j){
            if (A(i,j)!=results[(i-1)*NY+j-1]) {
                std::cout << "Failure with lambda capture\n";
                std::cout << "Array failure\n";
                return -1;
            }
        }
#endif
    std::cout << "Tests passed\n\n";    
}
