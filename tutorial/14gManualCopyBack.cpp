#include <iostream>
#include "far.h"

void ptrFunc(int *data, int size){
    for(int i=0; i<size; i++){
        data[i]=i;
    }
}

int main(){

    far::Array<int,2> a(3,3);
    {
        a=-1; //Set all elements to -1 so that you can see all changed elements
        auto co = far::makeCopyOut(a); //Create a copy out object
        ptrFunc(co, 9); //Alter the whole array
        co.copyBack(); //Explicitly copy back
        std::cout << "This copyBack was a noOp because the array is contiguous\n";
        std::cout << far::gridPrint(a) << std::endl; // This will have already updated
    }
    {
        a=-1; //Set back to -1
        auto co = far::makeCopyOut(a(far::Range(2,3),far::Range(1,3))); //Create a copy out object for a non-contiguous range
        ptrFunc(co, 6); //Alter only a non-contiguous range
        co.copyBack(); //Explicitly copy back
        std::cout << "This copyBack has caused a copy to happen and the array will have been updated\n";
        std::cout << far::gridPrint(a) << std::endl;
    }
    std::cout << "CopyOut object has gone out of scope, which has triggered another copy, but is otherwise harmless\n";
    std::cout << far::gridPrint(a) << std::endl;
}
