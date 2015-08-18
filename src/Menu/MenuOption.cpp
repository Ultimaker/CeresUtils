#include "Menu/MenuOption.h"


MenuOption::MenuOption(string n, string d, string i )
{
    name = n; description = d; info = i;
}

MenuOption::MenuOption(string n, string d, string i, string color )
: MenuOption(n,d,i)
{
    this->color = color;
}


MenuOption::~MenuOption()
{
    //dtor
}


string MenuOption::showDescription(int pos) // show with description
{
    return StringUtils::addWhiteSpaceUntillLengthIs(5, (to_string(pos+1) + ")") )
        + color + StringUtils::addWhiteSpaceUntillLengthIs(20, name)  + StringUtils::clr_original + description;
}

string MenuOption::showInfo(int pos) // show with info
{
    return StringUtils::addWhiteSpaceUntillLengthIs(5, ( to_string(pos+1) + ")" ) )
        + color + StringUtils::addWhiteSpaceUntillLengthIs(20, name)  + StringUtils::clr_original + info;
}
string MenuOption::showInfo() // show with info
{
    return name + "\t" + info;
}
