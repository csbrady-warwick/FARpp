#include <iostream>
#include "far.h"
#include "compare.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing rrspacing " << argv[0] << "\n";
    if (softCompare(rrspacing(-3.0),6755399441055744.0)){
        std::cout << "rrspacing(-3.0) failed\n";
        return -1;
    }
		Array<float,1> result = literal<float>(8388608.00,8388608.00,12582912.0,8388608.00);
		Array<float,1> rr = rrspacing(literal<float>(1.0,2.0,3.0,4.0));
		for (size_t i=1;i<result.getSize();++i){
			if (softCompare(rr(i),result(i))){
				std::cout << "rrspacing array failure\n";
				return -1;
			}
		}
    std::cout << "All tests passed\n\n";
}
