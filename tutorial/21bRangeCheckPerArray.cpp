#include <iostream>
#include "far.h"

int main() {

    far::Array<int,2> a(10,10);
    far::Array<int,2,far::bounds_check_state::bc_always> b(10,10);

    a=1;b=2;

    //This will not cause any problems because it will calculate a point
    //Within the bounds of the underlying storage, but it is still incorrect
    //No error will be thrown because bounds checking is off for this array
    try{
        std::cout << "Out of range element in unchecked array is " << a(11,1) << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "Caught exception in unchecked array: " << e.what() << std::endl;
    }

    //This will cause an error because bounds checking is on for this array
    try{
        std::cout << "Out of range element in checked array is " << b(11,1) << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "Caught exception in checked array: " << e.what() << std::endl;
    }

    a=b;
    std::cout << "Unchecked array has been assigned a value from checked array\n";
    std::cout << "Smallest element in unchecked array is " << far::minval(a) <<"\n";
    std::cout << "Smallest element in checked array is " << far::minval(b) << "\n";

}