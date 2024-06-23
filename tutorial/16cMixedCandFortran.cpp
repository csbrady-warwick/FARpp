#include <iostream>
#include "far.h"

int main(){

    far::FortranArray<int,2> a = far::reshape(far::linspace(1,20,20),5,4);
    far::CArray<int,2> b = a;

    std::cout << "Fortran array\n";
    std::cout << far::gridPrint(a)<< "\n";
    std::cout << "In underlying order\n";
    for (auto e: a) std::cout << e << " ";
    std::cout << "\n\n";

    std::cout << "C array initialised by assigning from Fortran array\n";
    std::cout << far::gridPrint(b)<< "\n\n";
    std::cout << "In underlying order\n";
    for (auto e: b) std::cout << e << " ";
    std::cout << "\n\n";

}