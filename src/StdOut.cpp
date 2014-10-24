#include "StdOut.h"
#include <string>
#include <iostream>

void StdOut::printLine(std::string str)
{
    std::cout << str << std::endl;
}

void StdOut::print(std::string str)
{
    std::cout << str;
}
