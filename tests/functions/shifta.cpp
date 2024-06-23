#include <iostream>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing shifta\n";
    if (shifta(uint8_t(0b10010001),3) != uint8_t(0b11110010)) {
        std::cout << "Unsigned scalar shift with leading 1 failed\n";
        return -1;
    }
    if (shifta(uint8_t(0b00010001),3) != uint8_t(0b00000010)) {
        std::cout << "Unsigned scalar shift without leading 1 failed\n";
        return -1;
    }
    if (shifta(int8_t(0b10010001),3) != int8_t(0b11110010)) {
        std::cout << "Signed scalar shift with leading 1 failed\n";
        return -1;
    }
    if (shifta(int8_t(0b00010001),3) != int8_t(0b00000010)) {
        std::cout << "Signed scalar shift without leading 1 failed\n";
        return -1;
    }

    if (shifta(uint16_t(0b1001000100000001),3) != uint16_t(0b1111001000100000)) {
        std::cout << "Unsigned 16 bit shift with leading 1 failed\n";
        return -1;
    }

    Array<uint8_t,1> a(3);
    a=uint8_t(0b10010001);
    if (any(shifta(a,3) != uint8_t(0b11110010))) {
        std::cout << "Unsigned array shift with leading 1 failed\n";
        return -1;
    }
    

    std::cout << "All tests passed\n\n";
}