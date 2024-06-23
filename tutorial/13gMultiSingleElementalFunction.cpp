#include <iostream>
#include "far.h"

template<far::elementalParameter<double,float> T_x, far::elementalParameter<double,float> T_mean, far::elementalParameter<double,float> T_stddev>
auto gaussian(const T_x &x, const T_mean &mean, const T_stddev &stdev){
    using T_x_inner = far::arrayInfo_t<T_x>;
    using T_mean_inner = far::arrayInfo_t<T_mean>;
    using T_stddev_inner = far::arrayInfo_t<T_stddev>;
    auto l = [](const T_x_inner &x, const T_mean_inner &mean, const T_stddev_inner &stdev){
        return exp(-(x-mean)*(x-mean)/(2*stdev*stdev));
    };
		return far::makeElemental<l>(std::forward<const T_x&>(x), std::forward<const T_mean&>(mean), std::forward<const T_stddev&>(stdev));
}

int main(){

	std::cout << gaussian(1.0,0.0,1.0) << "\n";
	std::cout << gaussian(1.0f,0.0f,1.0f) << "\n";
	std::cout << gaussian(1.0,0.0f,1.0) << "\n";

}
