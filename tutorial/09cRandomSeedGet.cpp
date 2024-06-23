#include <iostream>
#include <sstream>
#include "far.h"

int main(){

    //Get the random seed
    far::Array<double,1> r(10);
    far::random_number(r);
    std::cout << "Initial 10 random numbers: " << r << std::endl;

    //Now save the RNG
    std::cout << "Saving RNG\n";
    std::stringstream ss;
    far::random_seed_get(ss);

    far::random_number(r);
    std::cout << "Next 10 random numbers: " << r << std::endl;

    //Now restore the RNG
    std::cout << "Restoring RNG\n";
    ss.seekg(0);
    far::random_seed_put(ss);
    far::random_number(r);
    std::cout << "The regenerated next 10 random numbers: " << r << std::endl;

}