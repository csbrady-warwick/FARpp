#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main()
{

  std::cout << "Test findloc with mask\n";

  Array<int, 2> a(NX, NY);
  Array<int, 1> loc;
  Array<bool,2> mask(NX, NY);

  a=reshape(literal(1,2,8,4,5,8,8,8,9), NX, NY);
  mask = true;
      {
        loc = findloc_with_mask(a, 8, mask, 1);
      }
  if (loc(1)!=3 || loc(2)!=3 || loc(3)!=1) {
    std::cout << "Failue with mask true" << std::endl;
    std::cout << "Error: loc(1)=" << loc(1) << ", loc(2)=" << loc(2) << ", loc(3)=" << loc(3) << std::endl;
    return -1;
  }

  mask=false;
      {
        loc = findloc_with_mask(a, 8, mask, 1);
      }
  if (loc(1)!=0 || loc(2)!=0 || loc(3)!=0) {
    std::cout << "Failue with mask true" << std::endl;
    std::cout << "Error: loc(1)=" << loc(1) << ", loc(2)=" << loc(2) << ", loc(3)=" << loc(3) << std::endl;
    return -1;
  }

  mask=true;
  mask(1,3)=false;
      {
        loc = findloc_with_mask(a, 8, mask, 1);
      }
  if (loc(1)!=3 || loc(2)!=3 || loc(3)!=2) {
    std::cout << "Failue with mask true" << std::endl;
    std::cout << "Error: loc(1)=" << loc(1) << ", loc(2)=" << loc(2) << ", loc(3)=" << loc(3) << std::endl;
    return -1;
  }
   std::cout << "All tests passed\n\n";
}