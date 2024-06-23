#include <iostream>
#include "far.h"

extern "C" float* getA(int nx,int ny);
extern "C" void printA();

int main(){
    int nx=5,ny=5;
    float *a = getA(nx,ny);
    far::Array<float,2> A;
    A.bind(a,nx,ny);
    std::cout << "Array" << std::endl;
    std::cout << far::gridPrint(A) << std::endl;
    std::cout << "Array slice" << std::endl;
    std::cout << far::gridPrint(A(far::Range(2,3),far::Range(3,5))) << std::endl;
    std::cout << "\n";

    //Now set it so that the values are reversed (i.e. nx*ny, nx*ny-1, ...)
    A = far::reshape(far::linspace(nx*ny,1,nx*ny),nx,ny);
    std::cout << "And printing from Fortran" << std::endl;
    printA();
}