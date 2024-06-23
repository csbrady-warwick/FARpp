#include <iostream>
#include "far.h"

template<typename T>
void ptrFunc(T *data, int size){
    std::cout << "Data from pointer : ";
    for(int i=0; i<size; i++){
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int main(){

    far::Array<int,2> a = reshape(far::linspace(1, 9, 9),3,3);

		//Can make the type unambiguous by specifying the template type
    ptrFunc<int>(far::makeCopyIn(a(far::Range(2,3),far::Range(1,3))), 6);

		//Can make the type unambiguous by casting
		ptrFunc(static_cast<int*>(far::makeCopyIn(a(far::Range(2,3),far::Range(1,3)))),6);

		//Can make unambiguous by using toPointer
		ptrFunc(far::makeCopyIn(a(far::Range(2,3),far::Range(1,3))).toPointer(),6);
}
