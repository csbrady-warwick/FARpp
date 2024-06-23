#include <iostream>
#include "far.h"
#ifdef __INTEL_LLVM_COMPILER
#define ITYPE int //I think this is an Intel compiler bug so work around it
#else
#define ITYPE std::integral
#endif

template<far::elementalParameter<ITYPE> T1, far::arrayParameter<double,1> T2>
auto lookup(const T1& index, T2& data){

	using T1_inner = far::arrayInfo_t<T1>;
	auto l = []( const T1_inner & index, T2 &data){return data(index);};
	return makeElemental<l>(std::forward<const T1&>(index), std::forward<T2&>(data));

}

int main(){

	far::Array<double,1> A = far::linspace(11,20,10);
	std::cout << lookup(1,A) << "\n";
	std::cout << lookup(far::linspace<int>(10,1,10),A) << "\n";

}
