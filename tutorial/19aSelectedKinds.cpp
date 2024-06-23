#include <iostream>
#include "far.h"

int main(){

    {
        using kind = far::selected_int_kind<1>;
        std::cout << "Size of selected_int_kind<1> is " << sizeof(kind) << std::endl;
    }

    {
        using kind = far::selected_int_kind<2>;
        std::cout << "Size of selected_int_kind<2> is " << sizeof(kind) << std::endl;
    }

    {
        using kind = far::selected_int_kind<4>;
        std::cout << "Size of selected_int_kind<4> is " << sizeof(kind) << std::endl;
    }

    {
        using kind = far::selected_int_kind<8>;
        std::cout << "Size of selected_int_kind<8> is " << sizeof(kind) << std::endl;
    }

    {
        using kind = far::selected_int_kind<16>;
        std::cout << "Size of selected_int_kind<16> is " << sizeof(kind) << std::endl;
    }

#ifdef FAR_INT128
    {
        using kind = far::selected_int_kind<32>;
        std::cout << "Size of selected_int_kind<32> is " << sizeof(kind) << std::endl;
    }
#endif

}