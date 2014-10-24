#include "Menu/Menu.h"
#include "StdOut.h"
#include <algorithm>
#include <functional>
#include <boost/algorithm/string/predicate.hpp> /// for find_if(...)
#include "StringUtils.h"
#include "VectorUtils.h"

using namespace std;
using namespace std::placeholders; /// for wildcards in lambda expressions

//int main() { Menu::main(); }




Menu::Menu(string t)
    : title_bar(t)
{
}

Menu::~Menu()
{
    for (int i = 0; i<options.size(); i++)
        delete options.at(i);
}


void Menu::present()
{
    while (returnToMenu)
        show();
}

void Menu::show()
{
    StdOut::printLine(title_bar);

    for (int i = 0; i< options.size(); i++)
        StdOut::printLine(options.at(i)->showDescription(i));

    StdOut::printLine("Enter selection:");

    string input;


    while (true)
    {
        while (! std::getline(std::cin, input))
        {
            cout << "can we ever get here? (Menu.cpp +/- line 60)" << endl;
        }

        vector<string> args = StringUtils::split(input, string("\\s+"));


        MenuOption* i = getMenuItemFromString(args.at(0));
        if (i == nullptr)
            cout << "Redo from start" << endl;
        else
        {
            vector<string> other_args(args.begin()+1, args.end());
            i->execute(other_args);
            return;
        }
    }
}

void Menu::addOption(MenuOption* option)
{
    options.push_back(option);
}

const vector<MenuOption*>& Menu::getOptions()
{
    return options;
}


MenuOption* Menu::getMenuItemFromString(const string& str)
{
    if ( StringUtils::isUInt(str)) // parse int
    {
        int i;
        i = stoi(str);
        if (i <= options.size() && i > 0)
            return options.at(stoi(str)-1);
        else
            return nullptr;
    }
    else // parse option name
    {
        function<bool (MenuOption*)> isMenuItemName = [&] (MenuOption* itemHere) -> bool { return boost::iequals(str, itemHere->name);};

        vector<MenuOption*>::iterator item = find_if(options.begin(), options.end(), isMenuItemName );

        if (item == options.end())
            return nullptr;
        else
            return *item;

    }
    return nullptr;
}




