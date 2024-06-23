#include <iostream>
#include <vector>
#include "far.h"

int main(){

    far::Array<double,2> a = far::reshape(far::linspace(0.0,2.0,5*4),5,4);
    auto mod = far::sin(a+1).stabilise(); //Stabilise the lazyArray (i.e. make copies of all rvalue parameters)

    std::vector<double> b;
		//Use standard C++ approach to fill the vector from the lazyArray
    std::copy(mod.begin(),mod.end(),std::back_inserter(b));
    std::cout << "Elements from the vector are: ";
    for (auto element : mod){
        std::cout << element << " ";
    }
    std::cout << "\n";

    std::cout << "Elements from the array are: " << far::sin(a+1) << "\n";
}
