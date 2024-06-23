#include <iostream>
#include <string>
#include "far.h"

using namespace far;

int main(){
    std::cout << "Testing verify\n";

    if (verify("Hello","Hello")!=0){
        std::cout << "Error: verify(\"Hello\",\"Hello\")!=0\n";
        return -1;
    }
    if (verify("Hello","oelH")!=0){
        std::cout << "Error: verify(\"Hello\",\"oelH\")!=0\n";
        return -1;
    }
    if (verify("Hello","He")!=3){
        std::cout << "Error: verify(\"Hello\",\"He\")!=3\n";
        return -1;
    }
    if (verify("Hello","oHel",true)!=0){
        std::cout << "Error: verify(\"Hello\",\"oHel\",true)!=0\n";
        return -1;
    }

    if (verify("Hello","Hel",true)!=5){
        std::cout << "Error: verify(\"Hello\",\"Hel\",true)!=5\n";
        return -1;
    }

    if (verify("Hello","Heo",false)!=3){
        std::cout << "Error: verify(\"Hello\",\"Heo\",false)!=3\n";
        return -1;
    }

    if (verify("Hello","Heo",true)!=4){
        std::cout << "Error: verify(\"Hello\",\"Heo\",true)!=4\n";
        return -1;
    }

    if (verify(std::string("Hello"),"eH")!=3){
        std::cout << "Error: verify(std::string(\"Hello\"),\"eH\")!=3\n";
        return -1;
    }

    if (verify(std::string("Hello"),std::string("He"))!=3){
        std::cout << "Error: verify(std::string(\"Hello\"),std::string(\"He\"))!=3\n";
        return -1;
    }

    Array<std::string,1> arr({"Hello","World"});
    if (any(verify(arr,"HeW")!=literal(3,2))){
        std::cout << "Error: verify(arr,\"HeW\")!=(3,2)\n";
        return -1;
    }
    
    std::cout << "Tests passed\n\n";
}