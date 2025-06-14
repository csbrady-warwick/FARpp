#include <iostream>
#include "far.h"

#define NX 3
#define NY 3

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

	std::cout << "Testing len_trim " << argv[0] << "\n";
	{
		char test[10] = "ABC      ";
		if (len_trim<int>(test)!=3){
			std::cout << "Constant length scalar string failure\n";
			return -1;
		}
	}

	{
		char test[10] = " ABC     ";
		if (len_trim<int>(test)!=4){
			std::cout << "Leading space failure\n";
			return -1;
		}
	}

	{
		char test[10] = "ABC x    ";
		if (len_trim<int>(test)!=5){
			std::cout << "Internal space failure\n";
			return -1;
		}
	}

	{
		char test[10] = "ABC     x";
		if (len_trim<int>(test)!=9){
			std::cout << "Final character failure\n";
			return -1;
		}
	}

	{
		Array<char[10],1> A(10);
		for (int i=1; i<=10; i++){
			strcpy(A(i),"ABC      ");
		}
		if (any(len_trim<int>(A)!=3)){
			std::cout << "Constant length array string failure\n";
			return -1;
		}
	}

	{
		const char *test = "Hello world   ";
		if (len_trim<int>(test)!=11){
			std::cout << "char* scalar string failure\n";
			return -1;
		}
	}

	{
		const char* test="Hello world ";
		Array<const char*,1> A(10);
		A=test;
		if (!all(len_trim<int>(A)==11)){
			std::cout << "char* array string failure\n";
			return -1;
		}
	}

	{
		std::string test = "Hello world  ";
		if (len_trim<int>(test)!=11){
			std::cout << "std::string scalar string failure\n";
			return -1;
		}
	}

	{
		Array<std::string,1> A(10);
		A= "Hello world  ";
		if (!all(len_trim<int>(A)==11)){
			std::cout << "std::string array string failure\n";
			return -1;
		}
	}

	std::cout << "Tests passed\n\n";
}
