#include "Menu/MenuItemFunctionPointer.h"

MenuItemFunctionPointer::MenuItemFunctionPointer(string n, string d, string i, MenuItemFunction e )
: MenuItemVirtual(n, d, i)
{
    executor = e;
}
MenuItemFunctionPointer::MenuItemFunctionPointer(string n, string d, string i, string color, MenuItemFunction e )
: MenuItemFunctionPointer(n, d, i, e)
{
    this -> color = color;
}

MenuItemFunctionPointer::~MenuItemFunctionPointer()
{
    //dtor
}
