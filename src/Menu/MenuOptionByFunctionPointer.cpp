#include "Menu/MenuOptionByFunctionPointer.h"

MenuOptionByFunctionPointer::MenuOptionByFunctionPointer(string n, string d, string i, MenuItemFunction e )
: MenuOption(n, d, i)
{
    executor = e;
}
MenuOptionByFunctionPointer::MenuOptionByFunctionPointer(string n, string d, string i, string color, MenuItemFunction e )
: MenuOptionByFunctionPointer(n, d, i, e)
{
    this -> color = color;
}

MenuOptionByFunctionPointer::~MenuOptionByFunctionPointer()
{
    //dtor
}
