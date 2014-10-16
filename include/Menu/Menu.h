#ifndef SIMPLEMENU_H
#define SIMPLEMENU_H

#include "Menu/MenuOption.h"
#include "Menu/MenuOptionByFunctionPointer.h"

#include <string>
#include <vector>
#include <functional>


using namespace std;

//typedef void (*MenuItemFunction)(vector<string>& args);
typedef function<void (vector<string>& args)> MenuItemFunction;


/**
* A simple menu: a menu title and a list of options selectable by number or name
* The [help] and [quit] option are automatically generated, but not automatically added to the menu.
* Once an option is executed, the user returns to the menu.
*/
class Menu
{
    public:
        bool returnToMenu = true;//!< set to false when [quit] is selected

        Menu(string title_bar);
        virtual ~Menu();

        void present(); //!< keep showing menu until [quit] is selected
        void addOption(MenuOption* option);//!< add option to the bottom of the menu
        MenuOption* getMenuItemFromString(const string& str);//!< parse user input string (option number or option name) (or nullptr if failed)

        const vector<MenuOption*>& getOptions();
    protected:
    private:
        void show();//!< show the menu and let the user select and execute the selected option
        string title_bar = "";
        vector<MenuOption*> options;


};

#endif // SIMPLEMENU_H
