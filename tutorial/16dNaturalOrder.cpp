#include <iostream>
#include "far.h"

int main(){

    far::CArray<int,2> a = far::reshape(far::linspace(1,20,20),5,4);
    far::CArray<int,2> b = far::reshape(far::toCArray(far::linspace(1,20,20)),5,4);

    std::cout << "Simple assign from reshape(linspace)\n";
    std::cout << far::gridPrint(a)<< "\n";
    std::cout << "In underlying order\n";
    for (auto e: a) std::cout << e << " ";
    std::cout << "\n\n";

    std::cout << "Converting linspace to C array before reshape\n";
    std::cout << far::gridPrint(b)<< "\n\n";
    std::cout << "In underlying order\n";
    for (auto e: b) std::cout << e << " ";
    std::cout << "\n\n";

}