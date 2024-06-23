#include <iostream>
#include "far.h"

int main(){

    far::Array<int,2> a = far::reshape(far::linspace(1,5*6,5*6),5,6);
		for (auto &el:a){
			el*=2;
		}
		std::cout << far::gridPrint(a) << "\n";

}
