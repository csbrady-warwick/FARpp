#include <iostream>
#include "far.h"

#define NX 10
#define NY 10

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing is_contiguous " << argv[0] << "\n";
    Array<double,2> A(NX,NY);

    if (!is_contiguous(A)){
        std::cout << "Failure - Simple array is not contiguous\n";
        return -1;
    }

    if (is_contiguous(A(Range(1,NX/2),Range(1,NY/2)))){
        std::cout << "Failure - Non contiguous slice is contiguous\n";
        return -1;
    }

    if (!is_contiguous(A(Range(1,NX),Range(1,NY)))){
        std::cout << "Failure - Whole array is not contiguous\n";
        return -1;
    }

    if (!is_contiguous(A(Range(1,NX),Range(1,3)))){
        std::cout << "Failure - Contiguous slice is not contiguous\n";
        return -1;
    }
#ifndef FAR_USE_C_INDEX
    if (!is_contiguous(A(Range(1,NX/2),1))){
        std::cout << "Failure - Contiguous reduced rank slice is not contiguous\n";
        return -1;
    }

    if (is_contiguous(A(1,Range(1,NY/2)))){
        std::cout << "Failure - Non-contiguous reduced rank slice is contiguous\n";
        return -1;
    }
#else

    if (!is_contiguous(A(1,Range(1,NY/2)))){
        std::cout << "Failure - Contiguous reduced rank slice is not contiguous\n";
        return -1;
    }   

    if (is_contiguous(A(Range(1,NX/2),1))){
				std::cout << "Failure - Non-contiguous reduced rank slice is contiguous\n";
        return -1;
    }

#endif


 std::cout << "Test successful\n\n";
 return 0;

}
