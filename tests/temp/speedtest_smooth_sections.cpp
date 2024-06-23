//#define DEFAULT_ZERO_LB

#include "far.h"
#include "timer.h"
#define NX 10
#define NY 10
#define ITS 200

using namespace far;

int main(){
	Array<double,2> data(Range(0,NX+1),Range(0,NY+1)), data2;
	data=0;
	data2.mold(data);
	//Set the boundaries on data
	//data=reshape(linspace(1,(NX+2)*(NY+2),(NX+2)*(NY+2)),NX+2,NY+2);
	//std::cout << lbound(data) << " : " << ubound(data) << "\n";
	Array<double,1> B;
	B.pointTo(data(0,Range(0,NY+1)));
	std::cout << B.index.stride[0] << "\n";
	data(0,Range(0,NY+1))=1;
	data(NX+1,Range(0,NY+1))=1;
	data(Range(0,NX+1),0)=1;
	data(Range(0,NX+1),NY+1)=1;

	std::cout << gridPrint(data) << "\n";
	return 0;


	timer t;
	t.begin("main loop");
//	std::cout << "Starting\n";
#pragma omp parallel
	{
		for (int its = 0; its<ITS;++its){
			//std::cout << "Iteration " << its << "\n";
			beginWorkshare();
			//Update the temporary
			data2(Range(1,NX),Range(1,NY)) = (
					data(Range(0,NX-1),Range(1,NY)) +
					data(Range(2,NX+1),Range(1,NY)) +
					data(Range(1,NX),Range(0,NY-1)) +
					data(Range(1,NX),Range(2,NY+1))) * 0.25;
			//Copy back
			data(Range(1,NX),Range(1,NY))=data2(Range(1,NX),Range(1,NY));
			endWorkshare();
#pragma omp barrier
		}
	}
//	std::cout << "Ending\n";
	t.end();
	std::cout << maxval(data(Range(1,NX),Range(1,NY))) << "\n";
	std::cout << minval(data(Range(1,NX),Range(1,NY))) << "\n";
	std::cout << sum(data(Range(1,NX),Range(1,NY)))/float(data.getSize()) << "\n";
}
