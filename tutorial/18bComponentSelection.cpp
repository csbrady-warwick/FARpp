#include <iostream>
#include "far.h"

using namespace far;

class demo{
	public:
	int ivalue;
	float fvalue;
};

int main(){

	Array<demo,1> a(10);
	for(int i=1;i<=10;i++){
		a(i).ivalue = i;
	}
	std::cout << "Printing integer value using component selection :";
	std::cout <<  a.selectComponent<&demo::ivalue>() << "\n\n";
	std::cout << "Changing floating point component using component selection :";
	a.selectComponent<&demo::fvalue>() = linspace<float>(0.1,1.0,10);
	for(int i=1;i<=far::size(a);i++){
		std::cout << a(i).fvalue << " ";
	}
	std::cout << "\n";

}
