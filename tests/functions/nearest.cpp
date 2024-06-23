#include <iostream>
#include "far.h"

using namespace far;

int main(){
    //Part of this test is because nearest doesn't work like std::nextafter
    //std::nextafter returns the next representable value in the direction of the second argument
    //nearest returns the nearest representable value using the sign of the second argument
    //>=0 returns the next representable value greater than the first argument
    //<0 returns the next representable value less than or equal to the first argument
    std::cout << "Testing nearest\n";
    if (nearest(1.0,1.0) == 1.0){
        std::cout << "Failure nearest(1.0,1.0)=1.0\n";
        return -1;
    }
    if (nearest(1.0,-1.0) == 1.0){
        std::cout << "Failure nearest(1.0,-1.0)=1.0\n";
        return -1;
    }
    if (nearest(1.0,1.0) == 1.0){
        std::cout << "Failure nearest(1.0,1.0)!=1.0\n";
        return -1;
    }
    if (nearest(nearest(1.0,-1.0),1.0)!=1.0){
        std::cout << "Failure out and back\n";
        return -1;
    }
    Array<float,1> A = linspace(1,10,10);
    Array<float,1> B = linspace(1,10,10);
    B-=5;
    Array<float,1> C = nearest(A,B);
    for (int i=1;i<=10;i++){
        if (i<5){
            if (C(i)>=A(i)){
                std::cout << "Failure array nearest < pivot\n";
                //return -1;
            }
        } else {
            if (C(i)<=A(i)){
                std::cout << "Failure array nearest > pivot\n";
                //return -1;
            }
        }
    }
    std::cout << "All tests passed\n\n";
}