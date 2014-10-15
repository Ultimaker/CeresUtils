#ifndef MENUFACTORY_H
#define MENUFACTORY_H

#include "Menu/SimpleMenu.h"

class MenuFactory
{
    public:
        MenuFactory(string titleBar);
        virtual ~MenuFactory();

        void addOption(MenuItemVirtual* item);
        SimpleMenu* create();

        static int test();

    protected:
        SimpleMenu* menu;
    private:
};

#endif // MENUFACTORY_H
