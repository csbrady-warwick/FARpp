#include <iostream>
#include "far.h"

template<far::anyRankArray<float,double> param>
void mean_and_stdev(param& a){
    double mean;
    mean = far::sum(a) / (double)a.size();
    double stdev;
    stdev = far::sqrt(far::sum(far::pow(a - mean, 2.0)) / (double)a.size());

    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Standard deviation: " << stdev << std::endl;
}

int main(){

    far::Array<float,2> a(3,3);

    // Fill the array with random numbers from a normal distribution
    // with mean 0 and standard deviation 1
    far::random_normal(a, 0.0f, 1.0f);
    std::cout << far::gridPrint(a) << std::endl;

    far::reallocate(a,1000,1000);
    far::random_normal(a, 0.0f, 4.0f);
    mean_and_stdev(a);

}