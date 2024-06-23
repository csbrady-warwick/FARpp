#include <iostream>
#include "far.h"

template<far::elementalParameter<double> T_x>
auto doubler(T_x &x){
    using T_x_inner = far::arrayInfo_t<T_x>;
    auto l = [](T_x_inner &x){
        T_x_inner y=x;
         x*=2;
        return y;
    };
    return far::makeElemental<l>(std::forward<T_x&>(x));
}

int main(){

    double d=2.0;
    auto u = doubler(d);
    std::cout << u << " x 2 = " << d << std::endl;

    far::Array<double,1> a = far::linspace<double>(1,10,10);
    auto v = doubler(a);
    std::cout << v << " x 2 = " << a << std::endl;

    far::Array<double,2> b = far::reshape(far::linspace<double>(1,9,9),3,3);
    auto w = doubler(b);
    std::cout << w << " x 2 = " << b << std::endl;

}
