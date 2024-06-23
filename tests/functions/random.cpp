#include <iostream>
#include <iomanip>
#include <sstream>
#include "far.h"
#include "compare.h"

using namespace far;

int main(){
    std::cout << "Testing random\n";

    if (random_seed_size() != std::mt19937::state_size) {
        std::cout << random_seed_size() << " != " << FAR_DEFAULT_GLOBAL_RNG::state_size << "\n";
        std::cerr << "random_seed_size failed\n";
        return 1;
    }
    Array<uint32_t, 1> seed(random_seed_size());
    for (size_t i = 0; i < seed.getSize(); ++i) {
        seed(i) = i;
    }
    random_seed_put(seed);
    std::stringstream ss;
    random_seed_get(ss);
    

    Array<double,2> a(3,3);
    random_number(a);
    if (any(a<0) || any(a>=1)) {
        std::cout << "random_number failed (result out of range)\n";
        return -1;
    }

    Array<double,2> hardresult = reshape(literal(
        0.60792720011863188300793581220204941928386688232421875,
        0.30584433453359427534934411596623249351978302001953125,
        0.7120931906545331369073892346932552754878997802734375,
        0.475698161205909020310400592279620468616485595703125,
        0.364980782214029020327217267549713142216205596923828125,
        0.421658514442418252965438796309172175824642181396484375,
        0.623657041154158431339737944654189050197601318359375,
        0.343144651284676138747187223998480476438999176025390625,
        0.2307958378666297993841993729802197776734828948974609375         
    ),3,3);
    for (int j=1; j<=3; ++j) {
        for (int i=1; i<=3; ++i) {
            if (softCompare(a(i,j), hardresult(i,j))) {
                std::cout << "random_number soft failed (Random numbers from seed does not match). This may not be an error\n";
            }
        }
    }

    ss.seekg(0);
    random_seed_put(ss);
    Array<double,2> b(3,3);
    random_number(b);
    if (any(a != b)) {
        std::cout << "random_seed_put/get failed\n";
        return 1;
    }

    RNGHandle rng1, rng2;
    random_seed_put(rng1, seed);
    random_seed_put(rng2, seed);

    random_number(rng1, a);
    random_number(rng2, b);
    if (any(a != b)) {
        std::cout << "random_number with handles failed\n";
        return 1;
    }

    std::cout << "Tests passed\n\n";
}
