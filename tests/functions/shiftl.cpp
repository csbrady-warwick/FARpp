#include <iostream>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing shiftl\n";
    if (shiftl(uint8_t(0b10010001),3) != uint8_t(0b10001000)) {
        std::cout << "Unsigned scalar shift failed\n";
        return -1;
    }
    if (shiftl(int8_t(0b10010001),3) != int8_t(0b10001000)) {
        std::cout << "Signed scalar shift failed\n";
        return -1;
    }

    if (shiftl(uint16_t(0b1001000100000001),3) != uint16_t(0b1000100000001000)) {
        std::cout << "Unsigned 16 bit shift failed\n";
        return -1;
    }

    Array<uint8_t,1> a(3);
    a=uint8_t(0b10010001);
    if (any(shiftl(a,3) != uint8_t(0b10001000))) {
        std::cout << "Unsigned array shift failed\n\n";
        return -1;
    }
    

    std::cout << "All tests passed\n";
}