#include <iostream>
#include "far.h"

template<far::elementalParameter<double> T_x, far::elementalParameter<double> T_mean, far::elementalParameter<double> T_stddev>
auto gaussian(const T_x &x, const T_mean &mean, const T_stddev &stdev){
    using T_x_inner = far::arrayInfo_t<T_x>;
    using T_mean_inner = far::arrayInfo_t<T_mean>;
    using T_stddev_inner = far::arrayInfo_t<T_stddev>;
    auto l = [](const T_x_inner &x, const T_mean_inner &mean, const T_stddev_inner &stdev){
        return exp(-(x-mean)*(x-mean)/(2*stdev*stdev));
    };
    return far::makeElemental<l>(std::forward<const T_x &>(x), std::forward<const T_mean&>(mean), std::forward<const T_stddev&>(stdev));
}

int main(){

    std::cout << "Gaussian function works on single values\n";
    std::cout << "Gaussian(1, 0, 1) = " << gaussian(1.0, 0.0, 1.0) << "\n";
    std::cout << "Gaussian(0, 0, 1) = " << gaussian(0.0, 0.0, 1.0) << "\n";
    std::cout << "Gaussian(-1, 0, 1) = " << gaussian(-1.0, 0.0, 1.0) << "\n";

    std::cout << "\n\n";

    far::Array<double,1> x = {-2,-1,0,1,2};
    far::Array<double,1> mean = {0,0,0,0,0};
    far::Array<double,1> stdev = {1,1,1,1,1};
    std::cout << "Gaussian function works when all parameters are arrays\n";
    std::cout << "Gaussian([-2,-1,0,1,2], [0,0,0,0,0], [1,1,1,1,1]) = " << gaussian(x, mean, stdev) << "\n";

    std::cout << "\n\n";

    std::cout << "Gaussian function works when only some parameters are arrays\n";
    std::cout << "Gaussian([-2,-1,0,1,2], 0, 1) = " << gaussian(x, 0.0, 1.0) << "\n";

    far::Array<double,2> x2d(5,5), mean2d(5,5), stdev2d(5,5);
    for (int i=1; i<=5; i++){
        x2d(i,far::Range()) = x;
        stdev2d(i,far::Range()) = stdev*i;
    }
    mean2d = 0.0;
    std::cout << "Gaussian function works with 2D arrays\n";
    std::cout << far::gridPrint(gaussian(x2d, mean2d, stdev2d)) << "\n";
    std::cout << "\n\n";

    std::cout << "Gaussian function works with array expressions\n";
    std::cout << far::gridPrint(gaussian(x2d, mean2d, stdev2d*2)) << "\n";
}
