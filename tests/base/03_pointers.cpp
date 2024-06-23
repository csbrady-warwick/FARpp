#include <iostream>
#include "far.h"

using namespace far;

int main(){

    std::cout << "Testing pointers\n";

    Array<int,3> A(10,20,30);
    A=1;
    Array<int,3> B;
    if (associated(B)){
        std::cout << "Pointer is associated before assignment\n";
        return -1;
    }
    B.pointTo(A);
    if (!associated(B)){
        std::cout << "Pointer is not associated after assignment\n";
        return -1;
    }
    if (any(A!=B)){
        std::cout << "Pointer does not equal target\n";
        return -1;
    }

    B=2;
    if (any(A!=B)){
        std::cout << "Pointer does not equal target after whole assignment\n";
        return -1;
    }

    B.pointTo(A(Range(),Range(1,2),Range(1,1)));
    B=3;
    for (size_t k=1;k<=A.getRankSize(3);k++){
        for (size_t j=1;j<=A.getRankSize(2);j++){
            for (size_t i=1;i<=A.getRankSize(1);i++){
                if (((j<=2 && k==1) && A(i,j,k)!=3) || ((j>2 || k!=1) && A(i,j,k)!=2)){
                    std::cout << i << " " << j << " " << k << " " << A(i,j,k) << "\n";
                    std::cout << "Pointer does not equal target after 2D partial range assignment\n";
                    return -1;
                }
            }
        }
    }

    A=2;
    Array<int,1> D;
    D.pointTo(A(Range(),1,1));
    D=3;
    for (size_t k=1;k<=A.getRankSize(3);k++){
        for (size_t j=1;j<=A.getRankSize(2);j++){
            for (size_t i=1;i<=A.getRankSize(1);i++){
                if (((j==1 && k==1) && A(i,j,k)!=3) || ((j!=1 || k!=1) && A(i,j,k)!=2)){
                    std::cout << i << " " << j << " " << k << " " << A(i,j,k) << "\n";
                    std::cout << "Pointer does not equal target after 1D partial range assignment\n";
                    return -1;
                }
            }
        }
    }

    B.pointTo();
    if (associated(B)){
        std::cout << "Pointer is associated after disassociation\n";
        return -1;
    }

    std::cout << "All tests passed\n";

}
