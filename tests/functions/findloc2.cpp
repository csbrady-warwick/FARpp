#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main()
{

	std::cout << "Testing findloc\n";

  Array<int, 2> a(NX, NY);
  Array<int, 1> loc;
  Array<bool,2> mask(NX,NY);

  a=0;
  mask=true;
  // Test for finding a single value in the correct location
  for (int j = NY; j >= 1; j--)
  {
    for (int i = NX; i >= 1 ; i--)
    {
      a(i, j) = 8;
      {
        loc = findloc_with_mask(a, 8, mask);
      }
      if (loc(1) != i || loc(2) != j)
      {
        std::cout << "Error all masked: loc(1) = " << loc(1) << " loc(2) = " << loc(2) << " i = " << i << " j = " << j << std::endl;
        return -1;
      }
    }
  }

  mask = false;
  // Test for finding a single value in the correct location
  for (int j = NY; j >= 1; j--)
  {
    for (int i = NX; i >= 1 ; i--)
    {
      mask=false;
      a(i, j) = 8;
      mask(i,j) = true;
      {
        loc = findloc_with_mask(a, 8, mask);
      }
      if (loc(1) != i || loc(2) != j)
      {
        std::cout << "Error one masked: loc(1) = " << loc(1) << " loc(2) = " << loc(2) << " i = " << i << " j = " << j << std::endl;
        return -1;
      }
    }
  }

  mask = false;
  // Test for finding a single value in the correct location
  for (int j = NY; j >= 1; j--)
  {
    for (int i = NX; i >= 1 ; i--)
    {
      a(i, j) = 8;
      {
        loc = findloc_with_mask(a, 8, mask);
      }
      if (loc(1) != defaultLB-1 || loc(2) != defaultLB-1)
      {
        std::cout << "Error all unmaske: loc(1) = " << loc(1) << " loc(2) = " << loc(2) << " i = " << i << " j = " << j << std::endl;
        return -1;
      }
    }
  }

	std::cout << "All tests passed\n";
  
}
