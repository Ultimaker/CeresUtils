#ifndef SIMPLEMENU_H
#define SIMPLEMENU_H

#include "Menu/MenuItemVirtual.h"
#include "Menu/MenuItemFunctionPointer.h"

#include <string>
#include <vector>
#include <functional>


using namespace std;

//typedef void (*MenuItemFunction)(vector<string>& args);
typedef function<void (vector<string>& args)> MenuItemFunction;



class SimpleMenu
{
    public:
        SimpleMenu(string titleBar);
        virtual ~SimpleMenu();
        void present();

        void addOption(MenuItemVirtual* item);

        MenuItemFunctionPointer* help;
        MenuItemFunctionPointer* quit;

    protected:
        virtual void helpFunction(vector<string>& args);
    private:
        void show();
        string titleBar = "";
        vector<MenuItemVirtual*> items;

        MenuItemVirtual* getMenuItemFromString(const string& str);

        bool returnToMenu = true;
};

#endif // SIMPLEMENU_H
