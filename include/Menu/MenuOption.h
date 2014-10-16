#ifndef MENUITEMVIRTUAL_H
#define MENUITEMVIRTUAL_H

#include <string>
#include <vector>
#include <functional>
#include "StringUtils.h"

using namespace std;

//typedef void (*MenuItemFunction)(vector<string>& args);
//typedef function<void (vector<string>& args)> MenuItemFunction;

/**
* The base class of MenuItems.
* A menu item is a selectable option which performs execute(args) on selection, which is a pure virtual function
*/
class MenuOption
{
    public:
        string name; //!< name of option in list
        string description; //!< short description
        string info; //!< mor eelaborate info (for help)
        string color = StringUtils::clr_white; //!< color of the menu option name

        virtual ~MenuOption();
        virtual void execute(vector<string>& args) = 0; //!< the function to be executed on selection of the option @param args the arguments supplied by the user

        string showDescription(int pos);  //! show with description (with position in menu option list)
        string showInfo(int pos);  //! show with info (with position in menu option list)
        string showInfo();         //! show with info
    protected:
        MenuOption(string name, string description, string info);
        MenuOption(string name, string description, string info, string color);
};


#endif // MENUITEMVIRTUAL_H
