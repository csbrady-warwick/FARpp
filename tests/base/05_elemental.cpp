#include <iostream>
#include "far.h"

using namespace far;

template<elementalParameter<int,float,double> T1, elementalParameter<int,float,double> T2>
decltype(auto) testElementalLazy(T1 &&a, T2 &&b){
    using iT1 = arrayInfo<T1>::type;
    using iT2 = arrayInfo<T2>::type;
    auto l = [](iT1 &a, const iT2 &b){
        return a+b;
    };
		return makeElemental<l>(a,b);
}

int main(){

    std::cout << "Testing elemental functions\n";

    if (testElementalLazy(1,1.0)!=2){
        std::cout << "Error in testElementalLazy(1,1.0)\n";
    }

    Array<int,1> a={1,2,3};
    float b =1.0;
    Array<int,1> v;

    auto U = toArray(testElementalLazy(a,b));
    if (!std::is_same_v<arrayInfo<decltype(U)>::type,float>){
        std::cout << "Wrong type in testElementalLazy(a,b)\n";
    }
    if (any(U!=literal<float>(2.0,3.0,4.0))){
        std::cout << "Error in testElementalLazy(a,b)\n";
    }

    std::cout << "All tests passed\n\n";

}
