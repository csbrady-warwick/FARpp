#include <iostream>
#include "far.h"
#include "timer.h"

#define NX 20//00//00
#define NY 20//00//00
#define ITERS 100000000

using namespace far;
int main(){

  Array<int64_t,2> A(NX,NY);
	int64_t B=0;
	A=1;
	timer t;
	t.begin("Sum test");
	for (int64_t i=0;i<ITERS;++i){
		B+=sum(A*2);
	}
	t.end();
	std::cout << B << "\n";
}
