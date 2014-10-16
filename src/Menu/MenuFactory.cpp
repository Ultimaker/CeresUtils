#include "Menu/MenuFactory.h"
#include "Menu/Menu.h"
#include "StdOut.h"


MenuFactory::MenuFactory(string title_bar)
: menu(new Menu(title_bar))
{
    //menu = new Menu(title_bar);
    help = new MenuOptionByFunctionPointer("help", "Menu info", "Show this list of menu option explanations.", StringUtils::clr_green,
                                           [&] (vector<string>& args ) -> void { return this->helpFunction(args); } );
    quit = new MenuOptionByFunctionPointer("quit", "Quit menu", "Leave this menu.", StringUtils::clr_red,
                                           [&] (vector<string>& args ) -> void { menu->returnToMenu = false; } );

}

MenuFactory::~MenuFactory()
{
    //dtor
}

void MenuFactory::addOption(MenuOption* item)
{
    menu->addOption(item);
}


Menu* MenuFactory::create()
{
    menu->addOption(help);
    menu->addOption(quit);
    return menu;
}



void MenuFactory::helpFunction(vector<string>& args)
{

    MenuOption* item = (args.size() == 0)? nullptr : menu->getMenuItemFromString(args.at(0));
    if (item == nullptr)
    {
        // cout <<  "non-specific help" << endl;
        auto options = menu->getOptions();
        for (int i = 0; i < options.size(); i++)
        {
            item = options.at(i);
            StdOut::out( item->showInfo(i) );
        }
    }
    else
    {
        // cout << "helpFunction" << endl;
        StdOut::out(  item->showInfo() );

    }
}


