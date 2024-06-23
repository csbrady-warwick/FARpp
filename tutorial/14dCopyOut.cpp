#include <iostream>
#include "far.h"

void ptrFunc(int *data, int size){
    for(int i=0; i<size; i++){
        data[i]=i;
    }
}

int main(){

    far::Array<int,2> a(3,3);
    a=-1; //Set all elements to -1 so that you can see all changed elements
    ptrFunc(far::makeCopyOut(a), 9); //Alter the whole array
    std::cout << far::gridPrint(a) << std::endl;
    a=-1; //Set back to -1
    ptrFunc(far::makeCopyOut(a(far::Range(2,3),far::Range(1,3))), 6); //Alter only a non-contiguous range
    std::cout << far::gridPrint(a) << std::endl;
}
