#include <iostream>
#include "far.h"
#include "timer.h"

#define NX 10
#define NY 10//00//000000

using namespace far;
int main(){

  Array<int64_t,2> A(NX,NY);
	int64_t B;
	A=1;
	timer t;
	t.begin("Sum test");
	B=sum(A*2);
	t.end();
	std::cout << B << "\n";
}
