#include <iostream>
#include <vector>
#include "far.h"

int main(){

    std::vector<int> v;
    v.resize(9);
    for(int i=0; i<9; i++){
        v[i] = i+1;
    }

    far::Array<int,2> a;
    //Bind the data of the vector to the array
    a.bind(v.data(), 3,3);
    std::cout << "You can now access the vector elements as an array\n";
    std::cout << "Array" << std::endl;
    std::cout << far::gridPrint(a) << std::endl;
    std::cout << "Array after adding 1 and doubling" << std::endl;
    std::cout << far::gridPrint((a+1)*2) << std::endl;

    a=far::reshape(far::linspace(9,1,9),3,3);
    std::cout << "Chaning the array changes the vector" << std::endl;
    for (auto &el:v){
        std::cout << el << " ";
    }
    std::cout << "\n";

}