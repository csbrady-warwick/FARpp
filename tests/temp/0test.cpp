//#define DEFAULT_ZERO_LB

#include "far.h"
#include "timer.h"
#define NX 10
#define NY 10
#define ITS 200

using namespace far;

int main(){
	Array<double,2> data(Range(0,NX+1),Range(0,NY+1));
	Array<double,1> d1 (10);
	data=0;

	std::cout << "Assigning (should be 10 elements)\n";
	Array<double,1> r;
	std::cout << data.rdata << "\n";
	std::cout << demangle<decltype(data(Range(0,NX+1),0))>() << "\n";
	std::cout << "Getting A\n";
	d1= data(Range(0,NX+1),0);//=1;
	std::cout << "Got A\n";
	std::cout << "1 " << d1.index.size << "\n";
	std::cout << "2 " << d1.index.slice_size << "\n";

	std::cout << "UUU " << &d1 << "\n";
	r.pointTo(data(Range(0,NX+1),0));

	std::cout << "3 " << r.index.size << "\n";
	std::cout << "4 " << r.index.slice_size << "\n";

	std::cout << "Rank = " << rank(r) << "\n";
	std::cout << "Stride = " << r.index.stride[0] << "\n";
	std::cout << "Assign done\n";
	r=1;
	data(0,Range(1,NY))=1;
	data(Range(0,NX+1),NY+1)=1;
	data(NX+1,Range(1,NY))=1;
	std::cout << gridPrint(data) << "\n";
}
