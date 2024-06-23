#include <iostream>
#include "far.h"

void ptrFunc(int *data, int size){
    std::cout << "Data from pointer : ";
    for(int i=0; i<size; i++){
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

void arrayFunc(const far::Array<int,2> &a){
    std::cout << "Data from array from contiguous object : ";
    std::cout << a << std::endl;
}

int main(){

    far::Array<int,2> a = reshape(far::linspace(1, 9, 9),3,3);
		//Print both using pointer and using array
    ptrFunc(far::makeCopyIn(a), 9);
    arrayFunc(far::makeCopyIn(a));

		//Now for a range
    ptrFunc(far::makeCopyIn(a(far::Range(2,3),far::Range(1,3))), 6);
    arrayFunc(far::makeCopyIn(a(far::Range(2,3),far::Range(1,3))));

		//Now for an expression. Note that this has to be makeCopyIn because writing to an expression
		//isn't ever valid
    ptrFunc(far::makeCopyIn(a*2), 9);
    arrayFunc(far::makeCopyIn(a*2));

}
