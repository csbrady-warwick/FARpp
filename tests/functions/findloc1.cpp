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

  a=0;
  // Test for finding a single value in the correct location
#ifndef FAR_USE_C_INDEX
  for (int j = NY; j >= 1; j--)
  {
    for (int i = NX; i >= 1 ; i--)
    {
#else
  for (int i = NX; i >= 1; i--)
  {
    for (int j = NY; j >= 1 ; j--)
    {
#endif
      a(i, j) = 8;
      {
        loc = findloc(a, 8);
      }
      if (loc(1) != i || loc(2) != j)
      {
        std::cout << "Error forwards: loc(1) = " << loc(1) << " loc(2) = " << loc(2) << " i = " << i << " j = " << j << std::endl;
        return -1;
      }
    }
  }

  a=0;
#ifndef FAR_USE_C_INDEX
  for (int j = 1; j <= NY; j++)
  {
    for (int i = 1; i <= NX; i++)
    {
#else
  for (int i = 1; i <= NX; i++)
  {
    for (int j = 1; j <= NY; j++)
    {
#endif
      a(i, j) = 8;
      {
        loc = findloc(a, 8, true);
      }
      if (loc(1) != i || loc(2) != j)
      {
        std::cout << "Error backwards: loc(1) = " << loc(1) << " loc(2) = " << loc(2) << " i = " << i << " j = " << j << std::endl;
        return -1;
      }
    }
  }

  a = reshape(linspace(1, NX * NY, NX * NY), NX, NY);
  int testvalue = a(NX / 2, NY / 2);
  a(NX, NY) = testvalue;
  {
    loc = findloc(a, testvalue);
  }

  if (loc(1) != NX / 2 || loc(2) != NY / 2)
  {
    std::cout << "Error first of two: loc(1) = " << loc(1) << " loc(2) = " << loc(2) << " i = " << NX / 2 << " j = " << NY / 2 << std::endl;
    return -1;
  }

  {
    loc = findloc(a, testvalue,true);
  }

  if (loc(1) != NX || loc(2) != NY)
  {
    std::cout << "Error second of two: loc(1) = " << loc(1) << " loc(2) = " << loc(2) << " i = " << NX / 2 << " j = " << NY / 2 << std::endl;
    return -1;
  }
  
	std::cout << "All tests passed\n\n";
}
