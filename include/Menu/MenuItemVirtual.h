#ifndef MENUITEMVIRTUAL_H
#define MENUITEMVIRTUAL_H

#include <string>
#include <vector>
#include <functional>
#include "StringUtils.h"

using namespace std;

//typedef void (*MenuItemFunction)(vector<string>& args);
typedef function<void (vector<string>& args)> MenuItemFunction;


class MenuItemVirtual
{
    public:
        string name;
        string description;
        string info;
        string color = StringUtils::clrWhite;

        virtual ~MenuItemVirtual();
        virtual void execute(vector<string>& args) = 0;

        string showD(int pos); // show with description
        string showI(int pos); // show with info
        string showI(); // show with info
    protected:
        MenuItemVirtual(string n, string d, string i);
        MenuItemVirtual(string n, string d, string i, string color);
};


#endif // MENUITEMVIRTUAL_H
