#include <iostream>
#include "far.h"

int main(){
    far::Array<long int,1> A = far::linspace(1,10,10);
    far::Array<long int*,1> ptr(10);

    //Get a pointer array to each element of A
    ptr = far::reference(A);

    //Use dereference and increment
    far::dereference(ptr) += 1;

    //Print the original array to see the values have changed
    std::cout << A << std::endl;
}