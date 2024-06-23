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
        co.unbind(); //This does nothing copying-wise because there is no need to copy back
        //But after this line co cannot be used at all
        std::cout << "This unbind is a no-op\n";
        std::cout << far::gridPrint(a) << std::endl; // This will have already updated
    }
    {
        a=-1; //Set back to -1
        auto co = far::makeCopyOut(a(far::Range(2,3),far::Range(1,3))); //Create a copy out object for a non-contiguous range
        ptrFunc(co, 6); //Alter only a non-contiguous range
        co.unbind(); //Explicitly unbind, causing a copy back
        std::cout << "This unbind has caused a copy to happen and the array will have been updated\n";
        std::cout << far::gridPrint(a) << std::endl;
    }
    std::cout << "CopyOut object has gone out of scope, which now does nothing\n";
    std::cout << far::gridPrint(a) << std::endl;
}
