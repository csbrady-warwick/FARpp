#include <string>
#include <iomanip>
#include <iostream>
#include "timer.h"

#define NX 10000
#define NY 10000
#define ITS 200

#define index(i,j) (i)*(NY+2)+(j)

int main(){
    double *data = new double[(NX+2)*(NY+2)];
    double *data2 = new double[(NX+2)*(NY+2)];
    for (int i = 0; i<(NX+2)*(NY+2);++i){
        data[i]=0;
        data2[i]=0;
    }
    //Set the boundaries on data
    for (int i = 0; i<NX+2;++i){
        data[index(i,0)]=1;
        data[index(i,NY+1)]=1;
    }
    for (int j = 0; j<NY+2;++j){
        data[index(0,j)]=1;
        data[index(NX+1,j)]=1;
    }
    timer t;
    t.begin("main loop");
    for (int its = 0; its<ITS;++its){
        for (int i = 1; i<NX+1;++i){
            for (int j = 1; j<NY+1;++j){
                data2[index(i,j)] = (
                        data[index(i-1,j)] +
                        data[index(i+1,j)] +
                        data[index(i,j-1)] +
                        data[index(i,j+1)]) * 0.25;
            }
        }
        for (int i = 1; i<NX+1;++i){
            for (int j = 1; j<NY+1;++j){
                data[index(i,j)]=data2[index(i,j)];
            }
        }
    }
    t.end();
    std::cout << std::setprecision(17);

    double mx = std::numeric_limits<double>::min();
    double mn = std::numeric_limits<double>::max();
    double sum = 0;
    for (int i = 1; i<NX+1;++i){
        for (int j = 1; j<NY+1;++j){
            mx = std::max(mx,data[index(i,j)]);
            mn = std::min(mn,data[index(i,j)]);
            sum += data[index(i,j)];
        }
    }
    sum /= double(NX*NY);
    std::cout << mx << std::endl;
    std::cout << mn << std::endl;
    std::cout << sum << std::endl;

}  
