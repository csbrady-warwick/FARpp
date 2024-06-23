#include <iostream>
#include "far.h"

class demo{
	private:
	int i;
	public:

	//Setter method
	void set_i(int val){
		i = val;
	}

	int& get_i(){
		return i;
	}

	int inc(int val){
		int temp = i;
		i+=val;
		return temp;
	}

	int inc(){
		int temp = i;
		i++;
		return temp;
	}

};

int main(){

	//Create an array of objects
	far::Array<demo,2> c(3,3);
	//Use callMethod to set the value of the object from a temporary
	//NB this will not allocate the array like normal assignment!
	c.callMethod<&demo::set_i>(far::reshape(far::linspace<int>(1,9,9),3,3));

	//Print the array, again using callMethod
	std::cout << "After setting using callMethod array is \n";
	std::cout << far::gridPrint(c.callMethod<&demo::get_i,far::ert::Array>()) << "\n\n";

	//Call the version of inc that takes no arguments
	//Note that have to manually cast the method to the correct type
	//to resolve the overload
	std::cout << "Original value of array returned from inc() \n";
	std::cout << far::gridPrint(c.callMethod<static_cast<int(demo::*)()>(&demo::inc)>()) << "\n\n";

	std::cout << "After calling inc() array is \n";
	std::cout << far::gridPrint(c.callMethod<&demo::get_i>()) << "\n\n";


	//Call the version of inc that takes an argument
	std::cout << "Original value of array returned from inc(2) \n";
	std::cout << far::gridPrint(c.callMethod<static_cast<int(demo::*)(int)>(&demo::inc)>(2)) << "\n\n";

	std::cout << "After calling inc(2) array is \n";
	std::cout << far::gridPrint(c.callMethod<&demo::get_i>()) << "\n\n";

}
