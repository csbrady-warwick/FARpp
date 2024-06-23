//#define DEFAULT_ZERO_LB

#include <iomanip>
#include "far.h"
#include "timer.h"
#define NX 1000
#define NY 1000
#define NZ 1000
#define ITS 20

using namespace far;

int main(){
	Array<double,3> data(Range(0,NX+1),Range(0,NY+1),Range(0,NZ+1)), data2;
	data=0;
	data2.mold(data);
	//Set the boundaries on data
	data(0,Range(),Range())=1;
	data(NX+1,Range(),Range())=1;
	data(Range(),0,Range())=1;
	data(Range(),NY+1,Range())=1;
	data(Range(),Range(),0)=1;
	data(Range(),Range(),NZ+1)=1;


	timer t;
	t.begin("main loop");
//	std::cout << "Starting\n";
	auto allX = Range(1,NX);
	auto allY = Range(1,NY);
	auto allZ = Range(1,NZ);
#pragma omp parallel
	{
		for (int its = 0; its<ITS;++its){
			//std::cout << "Iteration " << its << "\n";
			beginWorkshare();
			//Update the temporary
			//std::cout << "Update\n";
			data2(allX,allY,allZ) = (
					data(Range(0,NX-1),allY,allZ) +
					data(Range(2,NX+1),allY,allZ) +
					data(allX,Range(0,NY-1),allZ) +
					data(allX,Range(2,NY+1),allZ) +
					data(allX,allY,Range(0,NZ-1)) +
					data(allX,allY,Range(2,NZ+1))
					) / 6.0;
			//Copy back
			//std::cout << "Copyback\n";
			data(allX,allY,allZ)=data2(allX,allY,allZ);
			endWorkshare();
#pragma omp barrier
		}
	}
//	std::cout << "Ending\n";
	t.end();
	std::cout << std::setprecision(17);
	std::cout << maxval(data(allX,allY,allZ)) << "\n";
	std::cout << minval(data(allX,allY,allZ)) << "\n";
	std::cout << sum(data(allX,allY,allZ))/float(data.getSize()) << "\n";
}
