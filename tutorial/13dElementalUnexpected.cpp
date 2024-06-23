#include <iostream>
#include "far.h"

template<far::elementalParameter<double> T_x>
auto doubler(const T_x &x){
    using T_x_inner = far::arrayInfo_t<T_x>;
    auto l = [](const T_x_inner &x){
        std::cout << "Using value " << x << std::endl;
        return x*2;
    };
    return far::makeElemental<l>(std::forward<const T_x&>(x));
}

template<far::elementalParameter<double> T_x>
auto alldoubler(T_x &x){
    using T_x_inner = far::arrayInfo_t<T_x>;
    auto l = [](T_x_inner &x){
        std::cout << "Using value " << x << std::endl;
        return x*2;
    };
    return far::makeElemental<l>(std::forward<T_x&>(x));
}

int main(){

    far::Array<double,1> a = far::linspace<double>(1,10,10);
    far::Array<double,1> b = a;
    far::Array<double,1> c = far::linspace<double>(-4,5,10);

		std::cout << "Testing lazy doubler\n";
		auto r1 = far::toArray(far::merge(a,doubler(b),c>0));
		std::cout << "\nTesting array doubler\n";
		auto r2 = far::toArray(far::merge(a,alldoubler(b),c>0));

		std::cout << "Result 1 is " << r1 << "\n";
		std::cout << "Result 2 is " << r2 << "\n";
}
