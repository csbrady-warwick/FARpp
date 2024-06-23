#include <iostream>
#include "far.h"

template<far::elementalParameter<double> T_x>
void doubler(T_x &x){
    using T_x_inner = far::arrayInfo_t<T_x>;
    auto l = [](T_x_inner &x){
         x*=2;
    };
    far::makeElemental<l>(std::forward<T_x&>(x));
}

int main(){

    double d=2.0;
    doubler(d);
    std::cout << "Doubler on scalar 2x2 = " << d << std::endl;

    far::Array<double,1> a = far::linspace<double>(1,10,10);
    doubler(a);
    std::cout << "Doubler on array 2x[1->10] = " << a << std::endl;

    far::Array<double,2> b = far::reshape(far::linspace<double>(1,9,9),3,3);
    doubler(b);
    std::cout << "Doubler on array 2 x {3x3}[1->9] = " << b << std::endl;

}
