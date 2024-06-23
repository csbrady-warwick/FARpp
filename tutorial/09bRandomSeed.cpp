#include <iostream>
#include "far.h"

int main(){

    int64_t seed_size;
    //Get the size of the random seed Fortran style
    far::random_seed_size(seed_size);
    //Get the size of the random seed C++ style
    seed_size = far::random_seed_size();
    far::Array<uint32_t,1> seed(seed_size);
    seed=14;
    far::random_seed_put(seed);

    //Get the random seed
    far::Array<double,1> r(10);
    far::random_number(r);
    std::cout << r << std::endl;

    //Reset the random seed and get a new random number
    far::random_seed_put(seed);
    far::random_number(r);
    std::cout << r << std::endl;

    //The random number should be the same as the first one


}