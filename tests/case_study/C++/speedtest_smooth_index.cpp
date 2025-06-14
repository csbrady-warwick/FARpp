
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
#ifndef FAR_USE_C_INDEX
			for (int j=1;j<=NY;++j){
				#pragma omp for
				for (int i=1;i<=NX;++i){
					data2(i,j) = (data(i-1,j) + data(i+1,j) + data(i,j-1) + data(i,j+1)) * 0.25;
				}
			}
#else
      for (int i=1;i<=NX;++i){
        #pragma omp for
        for (int j=1;j<=NY;++j){
          data2(i,j) = (data(i-1,j) + data(i+1,j) + data(i,j-1) + data(i,j+1)) * 0.25;
        }
      }
#endif
			//Copy back
      beginWorkshare();
			data(Range(1,NX),Range(1,NY))=data2(Range(1,NX),Range(1,NY));
      endWorkshare();
#pragma omp barrier
		}
	}
	t.end();
	std::cout << std::setprecision(17);
	std::cout << maxval(data(Range(1,NX),Range(1,NY))) << "\n";
	std::cout << minval(data(Range(1,NX),Range(1,NY))) << "\n";
	std::cout << sum(data(Range(1,NX),Range(1,NY)))/float(data(Range(1,NX),Range(1,NY)).getSize()) << "\n";
}
