#include<iostream>
#include "far.h"

far::Array<int,2> test();

int main(){

	auto b = test();
	std::cout << far::gridPrint(b) << "\n";

}
