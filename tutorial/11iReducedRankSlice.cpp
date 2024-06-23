#include <iostream>
#include "far.h"

int main(){
    far::Array<int,3> A = reshape(far::linspace<int>(1,27,27),3,3,3);

    std::cout << "\nSize of slice (Range(),Range(1,1),Range()) is " << far::shape(A(far::Range(),far::Range(1,1),far::Range())) << "\n\n";
    std::cout << "Size of slice (Range(),1,Range()) is " << far::shape(A(far::Range(),1,far::Range())) << "\n\n";

    far::Array<int,2> Slice = A(far::Range(),2,far::Range());
    std::cout << "Slice is \n" << far::gridPrint(Slice) << "\n\n";

    far::Array<int,1> Slice1D;
    Slice1D.pointTo(Slice(2,far::Range(1,2)));
    std::cout << "Slice(2,1:2) is " << Slice1D << "\n\n";

		Slice1D.pointTo(Slice(far::Range(3,1,-1),2));
		std::cout << "Slice(3:1:-1,2) " << Slice1D << "\n\n";

    std::cout << "Slicing straight from original array " << A(far::Range(3,1,-1),2,2) << "\n\n";

    std::cout << "Slice of slice notation " << A(far::Range(),2,far::Range())(far::Range(3,1,-1),2) << "\n\n";
}
