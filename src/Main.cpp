#include "parse.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "Too few arguments." << std::endl;
        return 0;
    }

    else if(argc > 2)
    {
        std::cout << "Too many arguments." << std::endl;
        return 0;
    }

    std::string filename = argv[1];
    Parse parser(filename);
    std::vector<std::string> firstpass = parser.add_symbols();
    parser.assemble(firstpass, filename);
    return 0;
}