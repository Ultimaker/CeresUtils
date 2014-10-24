#ifndef STDOUT_H
#define STDOUT_H

#include <string>

class StdOut
{
    public:
        static void printLine(std::string str); //!< std::cout << str << std::endl;
        static void print(std::string str);
    protected:
    private:
};

#endif // STDOUT_H
