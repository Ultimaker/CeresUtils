#ifndef MENUITEMFUNCTIONPOINTER_H
#define MENUITEMFUNCTIONPOINTER_H

#include <Menu/MenuOption.h>
#include <string>
#include <vector>
#include <functional>


using namespace std;

typedef function<void (vector<string>& args)> MenuItemFunction;

/**
* An instantiation of MenuOption which can use function pointers as well as lambda expressions to specify the execute(args) function
*/
class MenuOptionByFunctionPointer: public MenuOption
{

    public:
        MenuItemFunction executor;//!< the function to be executed by execute(args)
        virtual ~MenuOptionByFunctionPointer();

        void execute(vector<string>& args) { executor(args); }

        MenuOptionByFunctionPointer(string name, string description, string info, MenuItemFunction executor);
        MenuOptionByFunctionPointer(string name, string description, string info, string color, MenuItemFunction executor);
};


#endif // MENUITEMFUNCTIONPOINTER_H
