#include <iostream>
#include "far.h"

far::Array<int,2> A;

extern "C" int* createArray(int nx,int ny);
extern "C" void printArray();

int* createArray(int nx,int ny){
    A = reshape(far::linspace(nx*ny,1,nx*ny),nx,ny);
    return A.data();
}

void printArray(){
    std::cout << "From C++" << std::endl;
    std::cout << far::gridPrint(A) << std::endl;
}