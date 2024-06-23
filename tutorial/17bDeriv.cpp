#include <iostream>
#include "far.h"

template<far::anyArray T_x, far::anyTypeArray<1> T_y, std::integral T_dir>
auto deriv(const T_x &x, const T_y&y, T_dir dir){
    constexpr int rank = far::arrayInfo<T_x>::rank;
    auto l = [](const far::indexInfo<rank> &ii, const T_x &x, const T_y &y, const T_dir &dir){
        auto cIndex = far::getTupleLevel(ii.indices,dir);
        if (cIndex == far::defaultLB || cIndex == far::defaultLB + static_cast<int64_t>(x.getRankSize(dir)) - 1) return 0.0;
        auto left = ii.indices;
        far::getTupleLevel(left,dir-1)--;
        auto right = ii.indices;
        far::getTupleLevel(right,dir-1)++;
        std::tuple<int64_t> leftIndex = far::getTupleLevel(left,dir-1), rightIndex = far::getTupleLevel(right,dir-1);
        return (far::getItem(y,right)-far::getItem(y,left))/(far::getItem(x,rightIndex)-far::getItem(x,leftIndex));
    };
    return far::makeElemental<l>(std::forward<const T_x&>(x),std::forward<const T_y&>(y),std::forward<T_dir>(dir));
}

int main(){
    far::Array<double,1> a = far::linspace<double>(0,M_PI*4.0,120), b, c;
    b = far::sin(a);
    c = deriv(a,b,1);
    for (size_t i=2;i<=a.getRankSize(1)-1;i++){
        std::cout << a(i) << " ," << b(i) << " ," << c(i) << std::endl;
    }
}