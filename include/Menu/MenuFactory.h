#ifndef MENUFACTORY_H
#define MENUFACTORY_H

#include "Menu/Menu.h"

/**
* Factory class for creating a menu
* Automatically adds the [help] and [quit] options to the bottom of the menu
* the menu is the owner of the menu item pointers.
*/
class MenuFactory
{
    public:

        /**
        * @param title_bar The text displayed above the menu option list.
        */
        MenuFactory(string title_bar);
        virtual ~MenuFactory();

        void addOption(MenuOption* item);
        Menu* create();

        static int test();

        MenuOptionByFunctionPointer* help;
        MenuOptionByFunctionPointer* quit;

    protected:
        Menu* menu;
        virtual void helpFunction(vector<string>& args);//!< the function executed when [help] is selected

    private:
};

#endif // MENUFACTORY_H
