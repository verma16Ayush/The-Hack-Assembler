#include "parse.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "Not a valid input file" << std::endl;
        return 0;
    }
    else if(argc > 2)
    {
        std::cout << "Too many arguments" << std::endl;
        return 0;
    }
    
}