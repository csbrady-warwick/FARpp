
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
	data(0,Range(0,NY+1),Range(0,NZ+1))=1;
	data(NX+1,Range(0,NY+1),Range(0,NZ+1))=1;
	data(Range(0,NX+1),0,Range(0,NZ+1))=1;
	data(Range(0,NX+1),NY+1,Range(0,NZ+1))=1;
	data(Range(0,NX+1),Range(0,NY+1),0)=1;
	data(Range(0,NX+1),Range(0,NY+1),NZ+1)=1;


	timer t;
	t.begin("main loop");
#pragma omp parallel
	{
		for (int its = 0; its<ITS;++its){
			for (int k=1;k<=NZ;++k){
				for (int j=1;j<=NY;++j){
					#pragma omp for
					for (int i=1;i<=NX;++i){
						data2(i,j,k) = (
							data(i-1,j,k) + data(i+1,j,k) 
							+ data(i,j-1,k) + data(i,j+1,k)
							+ data(i,j,k-1) + data(i,j,k+1)
						) /6.0;
					}
				}
			}
			//Copy back
			data(Range(1,NX),Range(1,NY),Range(1,NZ))=data2(Range(1,NX),Range(1,NY),Range(1,NZ));
#pragma omp barrier
		}
	}
	t.end();
	std::cout << std::setprecision(17);
	std::cout << maxval(data(Range(1,NX),Range(1,NY),Range(1,NZ))) << "\n";
	std::cout << minval(data(Range(1,NX),Range(1,NY),Range(1,NZ))) << "\n";
	std::cout << sum(data(Range(1,NX),Range(1,NY),Range(1,NZ)))/float(data(Range(1,NX),Range(1,NY),Range(1,NZ)).getSize()) << "\n";
}
