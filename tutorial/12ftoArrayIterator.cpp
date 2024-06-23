#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "far.h"

int main(){
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    far::Array<int,1> a = far::toArray(v); //Convert iterable to far::Array
    std::cout << "Vector to FAR++ rank 1 array\n" << a << "\n\n";

    std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    far::Array<int,2> b = far::reshape(far::toArray(l),3,3);
    std::cout << "List to FAR++ rank 2 array\n";
    std::cout << far::gridPrint(b) << "\n\n";

    std::deque<int> d = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    far::Array<int,2> c(3,3);
    auto cIter = c.begin();
    for(auto &val : d){
        *cIter = val;
        cIter++;
    }
    std::cout << "Deque to FAR++ rank 2 array using iterator assignment to array\n";
    std::cout << far::gridPrint(c) << "\n\n";

    c=0;
    std::copy(v.begin(), v.end(), c.begin());
    std::cout << "Vector to FAR++ rank 2 array using std::copy\n";
    std::cout << far::gridPrint(c) << "\n";

}
