#include <string>
#include <iomanip>
#include <iostream>
#include "timer.h"

#define NX 1000ll
#define NY 1000ll
#define NZ 1000ll
#define ITS 20

#define index(i,j,k) i*(NY+2)*(NZ+2)+j*(NZ+2)+k

int main(){
    double *data = new double[(NX+2)*(NY+2)*(NZ+2)];
    double *data2 = new double[(NX+2)*(NY+2)*(NZ+2)];
    for (int i = 0; i<(NX+2)*(NY+2)*(NZ+2);++i){
        data[i]=0;
        data2[i]=0;
    }
    //Set the boundaries on data
    for (int i = 0; i<NX+2;++i){
        for (int j = 0; j<NY+2;++j){
            data[index(i,j,0)]=1;
            data[index(i,j,NZ+1)]=1;
        }
    }
    for (int i = 0; i<NX+2;++i){
        for (int k = 0; k<NZ+2;++k){
            data[index(i,0,k)]=1;
            data[index(i,NY+1,k)]=1;
        }
    }
    for (int j = 0; j<NY+2;++j){
        for (int k = 0; k<NZ+2;++k){
            data[index(0,j,k)]=1;
            data[index(NX+1,j,k)]=1;
        }
    }
    timer t;
    t.begin("main loop");
    for (int its = 0; its<ITS;++its){
        for (int i = 1; i<NX+1;++i){
            for (int j = 1; j<NY+1;++j){
                for (int k = 1; k<NZ+1;++k){
                    data2[index(i,j,k)] = (
                            data[index(i-1,j,k)] +
                            data[index(i+1,j,k)] +
                            data[index(i,j-1,k)] +
                            data[index(i,j+1,k)] +
                            data[index(i,j,k-1)] +
                            data[index(i,j,k+1)]) * 0.16666666666666666666666666666667;
                }
            }
        }
        for (int i = 1; i<NX+1;++i){
            for (int j = 1; j<NY+1;++j){
                for (int k = 1; k<NZ+1;++k){
                    data[index(i,j,k)]=data2[index(i,j,k)];
                }
            }
        }
    }
    t.end();
    std::cout << std::setprecision(17);
}  
