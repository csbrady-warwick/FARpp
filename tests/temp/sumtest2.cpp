#include <iostream>
#include "far.h"
#include "timer.h"

#define ITS 200//0
#define N 30//100
#define NX N
#define NY N
#define NZ N
#define NA N
#define NB N

using namespace far;
int main(){

  Array<int64_t,5> A(NX,NY,NZ,NA,NB);
	int64_t B;
  int64_t a,i;
	bool f;
	A=2;
	timer t;
	t.begin("Sum test");
	for (int i=0;i<ITS;++i){
		//B=sum(A*2);
		a=count((A*2)>1);
		//f=any(A<2);
	}
	t.end();
	std::cout << a << "\n";
	std::cout << B << "\n";
	std::cout << f << "\n";
}
