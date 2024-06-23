#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main(){

	std::cout << "Testing fraction\n";
	if (softCompare(fraction(double(128)),0.5)) {
		std::cout << "Fraction double failure\n";
		return -1;
	}

	if (softCompare(fraction(float(128)),0.5)) {
		std::cout << "Fraction float failure\n";
		return -1;
	}

	if (softCompare(fraction(double(127)), 0.99218750000000000)) {
		std::cout << "Inexact double fraction failure\n";
		return -1;
	}

	Array<double, 2> a(NX, NY);
	Array<double, 2> b;
	a=128;
	b=fraction(a);
	for (int j=1;j<=NY;++j)
		for (int i=1;i<=NX;++i){
			if (softCompare(b(i,j),0.5)) {
				std::cout << "Array failure\n";
				return -1;
			}
		}
	std::cout << "Tests passed\n\n";
}
