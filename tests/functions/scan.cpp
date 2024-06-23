#include <iostream>
#include <string>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing scan\n";
    
    if (scan("Hello","e")!=2){
        std::cout << "Error: scan(\"Hello\",\"e\")!=2\n";
        return -1;
    }
    if (scan("Hello","z")!=0){
        std::cout << "Error: scan(\"Hello\",\"z\")!=0\n";
        return -1;
    }
    if (scan("Hello","l")!=3){
        std::cout << "Error: scan(\"Hello\",\"l\")!=3\n";
        return -1;
    }
    if (scan("Hello","l",true)!=4){
        std::cout << "Error: scan(\"Hello\",\"l\",true)!=4\n";
        return -1;
    }

    if (scan("Hello","Ho")!=1){
        std::cout << "Error: scan(\"Hello\",\"Ho\")!=1\n";
        return -1;
    }

    if (scan("Hello","Ho",true)!=5){
        std::cout << "Error: scan(\"Hello\",\"Ho\",true)!=5\n";
        return -1;
    }

    if (scan(std::string("Hello"),"e")!=2){
        std::cout << "Error: scan(std::string(\"Hello\"),\"e\")!=2\n";
        return -1;
    }

    if (scan(std::string("Hello"),std::string("Ho"))!=1){
        std::cout << "Error: scan(std::string(\"Hello\"),std::string(\"Ho\"))!=1\n";
        return -1;
    }

    Array<std::string,1> arr({"Hello","World"});
    if (any(scan(arr,"o")!=literal(5,2))){
        std::cout << "Error: scan(arr,\"o\")!=5\n";
        return -1;
    }
    
    std::cout << "Tests passed\n\n";
}