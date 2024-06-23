#include <iostream>
#include "far.h"

int main(){
    far::Array<int,3> A = reshape(far::linspace<int>(1,60,60),3,4,5);

    std::cout << "A is a 3x4x5 array of the elements from 1 to 60\n";

    far::Array<int,2> B;
    B.pointTo(A,12,5);
    std::cout << "Remapping A to 12x5 array\n";
    std::cout << far::gridPrint(B) << "\n\n";

    B.pointTo(A,4,15);
    std::cout << "Remapping A to 4x15 array\n";
    std::cout << far::gridPrint(B) << "\n\n";

    B.pointTo(A,far::Range(-6,5),5);
    std::cout << "Remapping A to 12x5 array with custom bounds\n";
    std::cout << far::gridPrint(B) << "\n\n";

    std::cout << "Remapping A(1:3,1:4,2) to a 3*4 array\n";
    std::cout << "This works because it is a contiguous array\n";
    B.pointTo(A(far::Range(1,3),far::Range(1,4),2),3,4);
    std::cout << far::gridPrint(B) << "\n\n";

    std::cout << "Remappying A(1:3,1:4,5) to a 12 element rank 1 array\n";
    far::Array<int,1> C;
    C.pointTo(A(far::Range(1,3),far::Range(1,4),5),12);
    std::cout << C << "\n\n";

    far::Array<int,2> D;
    D.pointTo(C,4,3);
    std::cout << "Remapping 1D slice back to 4x3 array\n";
    std::cout << far::gridPrint(D) << "\n\n";
    
    std::cout << "Using remapped pointer to set (1:3:2,1:2)*=-1 in reformed 4*3 slice\n";
    D(far::Range(1,3,2),far::Range(1,2))*=-1;
    std::cout << "Reformed slice after modification\n";
    std::cout << far::gridPrint(D) << "\n\n";
    std::cout << "Original array after modification\n";
    std::cout << far::gridPrint(A(far::Range(),far::Range(),5)) << "\n";
}
