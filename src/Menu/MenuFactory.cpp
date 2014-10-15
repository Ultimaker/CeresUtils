#include "Menu/MenuFactory.h"
#include "Menu/SimpleMenu.h"


MenuFactory::MenuFactory(string titleBar)
{
    //ctor
    menu = new SimpleMenu(titleBar);
}

MenuFactory::~MenuFactory()
{
    //dtor
}


void MenuFactory::addOption(MenuItemVirtual* item)
{
    menu->addOption(item);
}


SimpleMenu* MenuFactory::create()
{
    menu->addOption(menu->help);
    menu->addOption(menu->quit);
    return menu;
}



