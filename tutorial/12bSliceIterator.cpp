#include <iostream>
#include "far.h"

int main(){

    far::Array<int,2> a = far::reshape(far::linspace(1,5*6,5*6),5,6);
    for (auto &el:a(far::Range(2,4),far::Range(1,3))){
      el*=-1;
    }
    std::cout << far::gridPrint(a) << "\n";

}
