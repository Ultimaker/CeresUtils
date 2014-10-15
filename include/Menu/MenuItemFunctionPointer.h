#ifndef MENUITEMFUNCTIONPOINTER_H
#define MENUITEMFUNCTIONPOINTER_H

#include <Menu/MenuItemVirtual.h>
#include <string>
#include <vector>
#include <functional>


using namespace std;

//typedef void (*MenuItemFunction)(vector<string>& args);
typedef function<void (vector<string>& args)> MenuItemFunction;


class MenuItemFunctionPointer: public MenuItemVirtual
{

    public:
        MenuItemFunction executor;
        virtual ~MenuItemFunctionPointer();

        void execute(vector<string>& args) { executor(args); }

        MenuItemFunctionPointer(string n, string d, string i, MenuItemFunction f);
        MenuItemFunctionPointer(string n, string d, string i, string color, MenuItemFunction f);
};


#endif // MENUITEMFUNCTIONPOINTER_H
