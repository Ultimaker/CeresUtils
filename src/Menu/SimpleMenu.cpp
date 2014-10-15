#include "Menu/SimpleMenu.h"
#include "StdOut.h"
#include <algorithm>
#include <functional>
#include <boost/algorithm/string/predicate.hpp>
#include "StringUtils.h"
#include "VectorUtils.h"

using namespace std;
using namespace std::placeholders;

//int main() { SimpleMenu::main(); }










void SimpleMenu::helpFunction(vector<string>& args)
{

    MenuItemVirtual* item = (args.size() == 0)? nullptr : getMenuItemFromString(args.at(0));
    if (item == nullptr)
    {
        // cout <<  "non-specific help" << endl;

        for (int i = 0; i<items.size(); i++)
        {
            item = items.at(i);
            cout << item->showI(i) << endl;
        }
    }
    else
    {
        // cout << "helpFunction" << endl;
        cout << item->showI() << endl;

    }
}


SimpleMenu::SimpleMenu(string t)
{
    //ctor

    help = new MenuItemFunctionPointer("help", "Menu info", "Show this list of menu option explanations.", StringUtils::clrGreen,
        [&] (vector<string>& args ) -> void { return this->helpFunction(args); } );
    quit = new MenuItemFunctionPointer("quit", "Quit menu", "Leave this menu.", StringUtils::clrRed,
        [&] (vector<string>& args ) -> void { returnToMenu = false; } );
    titleBar = t;
}

SimpleMenu::~SimpleMenu()
{
    //dtor
    for (int i = 0; i<items.size(); i++)
        delete items.at(i);
}


void SimpleMenu::present()
{
    while (returnToMenu)
        show();

}
void SimpleMenu::show()
{
    StdOut::out(titleBar);

    for (int i = 0; i< items.size(); i++)
        StdOut::out(items.at(i)->showD(i));

    string input;


    while (true)
    {
        while (! std::getline(std::cin, input))
        {
            cout << "can we ever get here? (SimpleMenu.cpp +/- line 80)" << endl;
        }

        vector<string> args = StringUtils::split(input, string("\\s+"));


        MenuItemVirtual* i = getMenuItemFromString(args.at(0));
        if (i == nullptr)
            cout << "Redo from start" << endl;
        else
        {
            vector<string> otherArgs(args.begin()+1, args.end());
            i->execute(otherArgs);
            return;
        }
    }

}

void SimpleMenu::addOption(MenuItemVirtual* item)
{
    items.push_back(item);
}

MenuItemVirtual* SimpleMenu::getMenuItemFromString(const string& str)
{
    if ( StringUtils::isUInt(str)) // parse int
    {
        int i;
        i = stoi(str);
        if (i <= items.size() && i > 0)
            return items.at(stoi(str)-1);
        else
            return nullptr;
    }
    else // parse option name
    {
        function<bool (MenuItemVirtual*)> isMenuItemName = [&] (MenuItemVirtual* itemHere) -> bool { return boost::iequals(str, itemHere->name);};

        vector<MenuItemVirtual*>::iterator item = find_if(items.begin(), items.end(), isMenuItemName );

        if (item == items.end())
            return nullptr;
        else
            return *item;

    }
        return nullptr;
}


