#include <iostream>
#include "far.h"

template<far::elementalParameter<double> T_x>
auto doubler(T_x &x){
    using T_x_inner = far::arrayInfo_t<T_x>;
    constexpr int rank = far::arrayInfo<T_x>::rank;
    auto l = [](const far::indexInfo<rank> &ii, T_x &x){
        T_x_inner &data=far::getItem(x,ii);
        return data*2;
    };
    return far::makeElemental<l>(x);
}

int main(){
    far::Array<double,1> a = far::linspace<double>(1,10,10);
    double d=6.7;
    std::cout << doubler(d) << "\n";
    std::cout << doubler(a) << "\n";
}
