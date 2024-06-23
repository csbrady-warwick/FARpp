#include <iostream>
#include "far.h"

struct demo{
	int i;
	void operator=(int i){this->i=i;}//Assign operator
};

inline std::ostream& operator<<(std::ostream& os, const demo& obj) {
	os << obj.i << " ";
	return os;
}

int main(){
	far::Array<demo,2> myArray(2,2); // Have to allocate array before assignment when assigning from non-array type

	myArray = 14; //Assign it

	std::cout << myArray << "\n";

}
