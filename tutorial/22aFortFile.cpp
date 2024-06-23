#include <iostream>
#include "far.h"

int main(){

    auto &output = far::fortFile(20);
    output << "Hello world";
    output.close();

}