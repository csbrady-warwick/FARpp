#include <iostream>
#include "far.h"

int main(){

    far::Array<int,2> a = reshape(far::linspace(1, 9, 9),3,3);
    int *data = a.data();
    for(size_t i=0; i<a.size(); i++){
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

}
