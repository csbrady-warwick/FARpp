#include <iostream>
#include "far.h"

int main(){

    int64_t seed_size;
    far::RNGHandle<std::minstd_rand0> rng1;
    far::RNGHandle<std::ranlux48> rng2;
    //Get the size of the random seed C++ style
    seed_size = far::random_seed_size(rng1);
    far::Array<uint32_t,1> seed(seed_size);
    seed=14;
    far::random_seed_put(rng1, seed);

    //Get this size using the Fortran interface
    far::random_seed_size(rng2, seed_size);
    far::reallocate(seed, seed_size);
    seed=14;
    far::random_seed_put(rng2, seed);

    //Get the random seed
    far::Array<double,1> r(10);
    far::random_number(rng1, r);
    std::cout << r << std::endl;

    //Reset the random seed and get a new random number
    far::random_number(rng2, r);
    std::cout << r << std::endl;

}
