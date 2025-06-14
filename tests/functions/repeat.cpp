#include <iostream>
#include "far.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){
    std::cout << "Testing repeat " << argv[0] << "\n";

    if (repeat("Hello",3) != "HelloHelloHello") {
        std::cout << "repeat failed, char*\n";
        return 1;
    }

    if (repeat(std::string("Hello"),3) != "HelloHelloHello") {
        std::cout << "repeat failed, std::string\n";
        return 1;
    }

    std::cout << "All tests passed\n\n";
}
