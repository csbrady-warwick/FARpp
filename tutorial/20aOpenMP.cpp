#include <iostream>
#include "far.h"
#include <omp.h>

int get_thread_num(){
  #ifdef _OPENMP
  return omp_get_thread_num();
  #else
  return 0;
  #endif
}

int main(){

    int threads = 1;
    #ifdef _OPENMP
    threads=omp_get_max_threads();
    #endif
    far::Array<int,1> a(threads*3);
    #pragma omp parallel
    {
        far::beginWorkshare();
        a=get_thread_num();
        far::endWorkshare();
    }

    std::cout << "a = " << a << std::endl;

}