#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main()
{

	std::cout << "Testing findloc 3\n";
  Array<int, 2> a(NX, NY);
  Array<int, 1> loc;

  a=reshape(literal(1,2,8,4,5,8,8,8,9), NX, NY);
      {
        loc = findloc(a, 8, 1);
      }
  if (loc(1)!=3 || loc(2)!=3 || loc(3)!=1) {
    std::cout << "Failue forwards in rank 1" << std::endl;
    std::cout << "Error: loc(1)=" << loc(1) << ", loc(2)=" << loc(2) << ", loc(3)=" << loc(3) << std::endl;
    return -1;
  }

      {
        loc = findloc(a, 8, 2);
      }
  if (loc(1)!=3 || loc(2)!=3 || loc(3)!=1) {
    std::cout << "Failue forwards in rank 2" << std::endl;
    std::cout << "Error: loc(1)=" << loc(1) << ", loc(2)=" << loc(2) << ", loc(3)=" << loc(3) << std::endl;
    return -1;
  }


      {
        loc = findloc(a, 8, 1, true);
      }
  if (loc(1)!=3 || loc(2)!=3 || loc(3)!=2) {
    std::cout << "Failue backwards in rank 1" << std::endl;
    std::cout << "Error: loc(1)=" << loc(1) << ", loc(2)=" << loc(2) << ", loc(3)=" << loc(3) << std::endl;
    return -1;
  }

      {
        loc = findloc(a, 8, 2, true);
      }
  if (loc(1)!=3 || loc(2)!=3 || loc(3)!=2) {
    std::cout << "Failue backwards in rank 2" << std::endl;
    std::cout << "Error: loc(1)=" << loc(1) << ", loc(2)=" << loc(2) << ", loc(3)=" << loc(3) << std::endl;
    return -1;
  }
  std::cout << "All tests passed\n\n";
}
