#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main(){

	std::cout << "Testing len\n";
	{
		char test[10] = "123456789";
		if (len<int>(test)!=10){
			std::cout << "Constant length scalar string failure\n";
			return -1;
		}
	}

	{
		Array<char[10],1> A(10);
		if (len<int>(A)!=10){
			std::cout << "Constant length array string failure\n";
			return -1;
		}
	}

	{
		const char *test = "Hello world";
		if (len<int>(test)!=11){
			std::cout << "char* scalar string failure\n";
			return -1;
		}
	}

	{
		const char* test="Hello world";
		Array<const char*,1> A(10);
		A= test;
		if (!all(len<int>(A)==11)){
			std::cout << "char* array string failure\n";
			return -1;
		}
	}

	{
		std::string test = "Hello world";
		if (len<int>(test)!=11){
			std::cout << "std::string scalar string failure\n";
			return -1;
		}
	}

	{
		Array<std::string,1> A(10);
		A= "Hello world";
		if (!all(len<int>(A)==11)){
			std::cout << "std::string array string failure\n";
			return -1;
		}
	}

	std::cout << "Tests passed\n\n";
}
