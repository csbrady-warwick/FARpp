#include <iostream>
//This forces the compiler to always give the int kind requested
//even if it is not the fastest
#define FAR_EXACT_INT_KIND
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing selected_int_kind\n";
    if constexpr(!std::is_same_v<selected_int_kind<1>,int8_t>){
        std::cout << "Error: selected_int_kind<1>!=int8_t\n";
        return -1;
    }

    if constexpr(!std::is_same_v<selected_int_kind<3>,int16_t>){
        std::cout << "Error: selected_int_kind<3>!=int16_t\n";
        return -1;
    }

    if constexpr(!std::is_same_v<selected_int_kind<5>,int32_t>){
        std::cout << "Error: selected_int_kind<5>!=int32_t\n";
        return -1;
    }

    if constexpr(!std::is_same_v<selected_int_kind<10>,int64_t>){
        std::cout << "Error: selected_int_kind<10>!=int64_t\n";
        return -1;
    }
    #ifdef FAR_INT128
    std::cout << "int128 support detected. Testing\n";
    if constexpr(!std::is_same_v<selected_int_kind<20>,FAR_INT128>){
        std::cout << "Error: selected_int_kind<20>!=FAR_INT128\n";
        return -1;
    }
    #else
    std::cout << "No int128 support. Skipping test\n";
    #endif

    std::cout << "Tests passed\n\n";
}
