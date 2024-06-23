#include <iostream>
#include "far.h"

using namespace far;

int main(){

    std::cout << "Testing lgt\n";
    if (lgt("Hello","World")){
        std::cout << "Failure, false positive const char*\n";
        return -1;
    }

    if (lgt("Hello","Hello")){
        std::cout << "Failure, false positive const char*\n";
        return -1;
    }

    if (!lgt("Hello","Alice")){
        std::cout << "Failure, false negative const char*\n";
        return -1;
    }

   {
    Array<char[10],1> A(3);
    Array<char[10],1> B(3);
    for (int i=1; i<=3; i++){
        strcpy(A(i),"Hello");
    }
    strcpy(B(1),"World");
    strcpy(B(2),"Hello");
    strcpy(B(3),"Alice");

    if (any(lgt(A,B)!=literal<bool>(false,false,true))){
        std::cout << "Array char[10] failure\n";
        return -1;
    }
   }

   {
    Array<std::string,1> A(3);
    Array<std::string,1> B(3);
    A="Hello";
    B = literal<std::string>("World","Hello","Alice");
    if (any(lgt(A,B)!=literal<bool>(false,false,true))){
        std::cout << "Array char[10] failure\n";
        return -1;
    }
   }

    std::cout << "Tests passed\n\n";
}