# FAR++

FAR++ is a tool designed to provide Fortran like array features in C++ to make it quicker and easier to develop scientific code. FAR++ aims to and generally achieves speed at or near that of Fortran and native C++ data structures. The code is licensed under the Apache v2.0 license so should be suitable for most users. 

N.B. While FAR++ aims to give C++ programmers as much of the power and simplicity of Fortran's arrays as possible, Modern Fortran is probably still the best language for array based numerical computation. Consider if Fortran might be a better development language for your project than C++ if working heavily with arrays.

## Simple use of FAR++

For detailed instructions and usage guidelines, please refer to the [manual.pdf](docs/manual.pdf) in the `docs` directory, but to quickly see FAR++ in action

```C++
//This is the simple example from the README
#include <iostream>
#include "far.h"

#define PI 3.14159265358979323846

int main(){
  //Create a rank 1 array of integers
  far::Array<int,1> Array1;
  //Set it to contain the 10 elements from 1 to 10
  Array1 = far::linspace<int>(1,10,10);

  std::cout << "Array1 values are " << Array1 << "\n";
  std::cout << "(Array1*2) values are " << Array1 * 2 << "\n";

  std::cout << "\n\n";

  //Create a rank 2 (3x2) array of doubles with the values 1 to 6
  far::Array<double,2> Array2 = {{1.0,2.0,3.0},{4.0,5.0,6.0}};
  far::Array<double,2> Array3; // Create rank 2 array of doubles (unsized)

  Array3.mold(Array2); // Size Array3 from Array2
  Array3 = PI/2.0; //Set every element of Array3 to PI/2
  Array2 *= Array3; // Multiply every element of Array2 by the corresponding element of Array3

  std::cout << "Array2 has values of " << Array2 << "\n"; //Print Array2
  std::cout << "Sine of Array2 is " << far::sin(Array2) << "\n";//Print the sine of Array2

  std::cout << "\n\n";

  std::cout << "Array 2 showing rows and columns is\n";
  std::cout << far::gridPrint(far::sin(Array2)) << "\n"; //Use built in grid printer to show rows and columns

  std::cout << "\n\n";

  //While you can change this, FAR++ by default is Fortran-like.
  //Column major arrays with the array index starting from 1
  for (int j=1;j<=2;++j){
    for (int i=1;i<=3;++i){
      Array3(i,j) = Array2(i,j);
    }
  }
  std::cout << "Setting Array3 to Array2 element by element " << Array3 << "\n";
}
```
