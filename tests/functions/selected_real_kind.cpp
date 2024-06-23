#include <iostream>
#include "far.h"

using namespace far;

int main(){

    std::cout << "Test selected_real_kind\n";

    if (!std::is_same_v<selected_real_kind<6,37>, float>){
        std::cout << "Error: selected_real_kind<6,37> != float\n";
        return -1;
    }

    if (!std::is_same_v<selected_real_kind<7,38>, double>){
        std::cout << "Error: selected_real_kind<6,38> != double\n";
        return -1;
    }

    if (!std::is_same_v<selected_real_kind<6,129>, double>){
        std::cout << "Error: selected_real_kind<6,129> != double\n";
        return -1;
    }

    if (!std::is_same_v<selected_real_kind<6,70>, double>){
        std::cout << "Error: selected_real_kind<6,70> != double\n";
        return -1;
    }
    if ( std::numeric_limits<double>::digits10 != std::numeric_limits<long double>::digits10 ||
        std::numeric_limits<double>::max_exponent10 != std::numeric_limits<long double>::max_exponent10){
        std::cout << "Long double support detected. Testing\n";
        if (!std::is_same_v<selected_real_kind<16,1024>, long double>){
            std::cout << "Error: selected_real_kind<15,1024> != long double\n";
            return -1;
        }

        if (!std::is_same_v<selected_real_kind<15,1024>, long double>){
            std::cout << "Error: selected_real_kind<15,1024> != long double\n";
            return -1;
        }

        if (!std::is_same_v<selected_real_kind<15,1024>, long double>){
            std::cout << "Error: selected_real_kind<15,1024> != long double\n";
            return -1;
        }
    } else {
        std::cout << "Long double is not distinct from double. Skipping long double tests\n";
    }

    std::cout << "Test passed\n\n";
}