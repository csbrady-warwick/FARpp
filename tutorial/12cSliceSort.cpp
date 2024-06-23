#include <iostream>
#include "far.h"

int main(){

    far::Array<int,2> a = far::reshape(far::linspace(1,5*6,5*6),5,6);
    for (int i=1;i<=5;i++){
        std::sort(a(i,far::Range()).begin(),a(i,far::Range()).end(),[](int a, int b){return a>b;});
    }
    std::cout << far::gridPrint(a) << "\n";

}
