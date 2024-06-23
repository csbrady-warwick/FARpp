#include <iostream>
#include "far.h"
#include "compare.h"

using namespace far;

int main(){
    std::cout << "Testing transfer\n";
    Array<int,1> A(2);
    Array<uint8_t,1> B(2*sizeof(int));

    A(1)=258;
    A(2)=2;
    B=transfer(A,B);

    //Transfer Array to Array
    //Work for both little and big endian
    if (!all(B==literal<uint8_t>(2,1,0,0,2,0,0,0)) && !all(B==literal<uint8_t>(0,0,1,2,0,0,0,2))){
        std::cout << "Error: transfer(A,B) doesn't match\n";
        return -1;
    }

    //Transfer scalar to Array
    int i=258;
    B=transfer(i,B);
    if (!all(B==literal<uint8_t>(2,1,0,0)) && !all(B==literal<uint8_t>(0,0,1,2))){
        std::cout << "Error: transfer(i,B) doesn't match\n";
        return -1;
    }

    //Transfer Array to scalar
    Array<uint8_t,1> C=literal<uint8_t>(5,1,0,0);
    i=transfer(C,i);
    if (i!=261 && i!=83951616){
        std::cout << "Error: transfer(C,i) doesn't match\n";
        return -1;
    }

    //Transfer float to float
    float f=1.234;
    i=transfer(f,1);
    f=0.0;
    f=transfer(i,1.0f);
    if (softCompare(f,1.234f)){
        std::cout << "Error: transfer(f,i) doesn't match\n";
        return -1;
    }

    std::cout << "All tests passed\n";
}