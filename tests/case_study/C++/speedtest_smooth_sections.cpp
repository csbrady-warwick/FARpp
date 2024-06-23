#include <iomanip>
#include "far.h"
#include "timer.h"
#define NX 10000
#define NY 10000
#define ITS 200

using namespace far;

int main(){
	Array<double,2> data(Range(0,NX+1),Range(0,NY+1)), data2;
	data=0;
	data2.mold(data);
	//Set the boundaries on data
	data(0,Range(0,NY+1))=1;
	data(NX+1,Range(0,NY+1))=1;
	data(Range(0,NX+1),0)=1;
	data(Range(0,NX+1),NY+1)=1;

	timer t;
	t.begin("main loop");
#pragma omp parallel
	{
		for (int its = 0; its<ITS;++its){
			beginWorkshare();
			//Update the temporary
			(data2(Range(1,NX),Range(1,NY))) = (
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
	t.end();
	std::cout << std::setprecision(17);
	std::cout << "Maxval :" << maxval(data(Range(1,NX),Range(1,NY))) << "\n";
	std::cout << "Minval :" << minval(data(Range(1,NX),Range(1,NY))) << "\n";
	std::cout << "Mean   :" << sum(data(Range(1,NX),Range(1,NY)))/float(data(Range(1,NX),Range(1,NY)).getSize()) << "\n";
}
