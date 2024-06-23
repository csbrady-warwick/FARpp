#include <iostream>
#include "far.h"

void ptrFunc(int *data, int size){
    for(int i=0; i<size; i++){
        data[i]*=-2;
    }
}

int main(){

    far::Array<int,2> a = reshape(far::linspace(1, 9, 9),3,3);

    std::cout << far::gridPrint(a) << std::endl;
    ptrFunc(far::makeCopyInOut(a), 9); //Alter the whole array
    std::cout << far::gridPrint(a) << std::endl;
    a=reshape(far::linspace(1, 9, 9),3,3);
    ptrFunc(far::makeCopyInOut(a(far::Range(2,3),far::Range(1,3))), 6); //Alter only a non-contiguous range
    std::cout << far::gridPrint(a) << std::endl;
}
