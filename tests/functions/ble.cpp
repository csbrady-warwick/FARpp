#include <iostream>
#include "far.h"
#include "compare.h"

#define NX 3
#define NY 3

using namespace far;

int main(){
	std::cout << "Testing ble\n";
	Array<int,2> A(NX,NY), B(NX,NY);
	A=2;B=1;
	if (any(ble(A,B))){
		std::cout << "2 BLE 1 failed\n";
		return -1;
	}
	A=1;B=2;
	if (!all(ble(A,B))){
		std::cout << "1 BLE 2 failed\n";
		return -1;
	}
	A=2;B=2;
	if (!all(ble(A,B))){
		std::cout << "2 BLE 2 failed\n";
		return -1;
	}

	A=-2;B=2;
	if (any(ble(A,B))){
		std::cout << "-2 BLE 2 failed\n";
		return -1;
	}

	A=2;B=-2;
	if (!all(ble(A,B))){
		std::cout << "2 BLE -2 failed\n";
		return -1;
	}
	std::cout << "Tests passed\n\n";
}
