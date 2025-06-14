#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing shiftr " << argv[0] << "\n";
    if (shiftr(uint8_t(0b10010001),3) != uint8_t(0b00010010)) {
        std::cout << "Unsigned scalar shift with leading 1 failed\n";
        return -1;
    }
    if (shiftr(uint8_t(0b00010001),3) != uint8_t(0b00000010)) {
        std::cout << "Unsigned scalar shift without leading 1 failed\n";
        return -1;
    }
    if (shiftr(int8_t(0b10010001),3) != int8_t(0b00010010)) {
        std::cout << "Signed scalar shift with leading 1 failed\n";
        return -1;
    }
    if (shiftr(int8_t(0b00010001),3) != int8_t(0b00000010)) {
        std::cout << "Signed scalar shift without leading 1 failed\n";
        return -1;
    }

    if (shiftr(uint16_t(0b1001000100000001),3) != uint16_t(0b0001001000100000)) {
        std::cout << "Unsigned 16 bit shift with leading 1 failed\n";
        return -1;
    }

    Array<uint8_t,1> a(3);
    a=uint8_t(0b10010001);
    if (any(shiftr(a,3) != uint8_t(0b00010010))) {
        std::cout << "Unsigned array shift with leading 1 failed\n";
        return -1;
    }
    

    std::cout << "All tests passed\n\n";
}
