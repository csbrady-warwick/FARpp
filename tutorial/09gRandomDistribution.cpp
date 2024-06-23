#include <iostream>
#include "far.h"

int main(){

    far::Array<float,2> a(3,3);
    std::weibull_distribution<float> dist(1.0f, 1.0f);

    // Fill the array with random numbers from a weibull distribution
    // with shape 1 and scale 1
    far::random_distribution(a, dist);

    std::cout << far::gridPrint(a) << std::endl;

}