#ifndef TESTING_H
#define TESTING_H
#include "StdOut.h"
#include "VectorUtils.h"
#include "StringUtils.h"
#include <iostream>
#include "Menu/SimpleMenu.h"
#include "Menu/MenuFactory.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;



static void someFunc(vector<string>& args)
{
    cout << "executing someFunc" << endl;
    cout << "args=" << VectorUtils::toString(args) << endl;
}



class Testing
{
    public:


/**
* StringUtils
*/


static void testSplitRegex()
{
    string str("Ik ben rex van de regex!");

    string r("\\s+");

    vector<string> splitted = StringUtils::split(str, r);

    cout << VectorUtils::toString( splitted ) << endl;

}

static void testSplit()
{
    string str("Ik ben stoer");

    vector<string> splitted = StringUtils::split(str, ' ');

    cout << VectorUtils::toString( splitted ) << endl;

}






/**
* VectorUtils
*/



static void testToString()
{
/*
    std::vector<int>* vec = new std::vector<int>();
    vec->push_back(1);
    vec->push_back(2);
    vec->push_back(3);
    vec->push_back(4);
    vec->push_back(5);
    */
    std::vector<string>* vec = new std::vector<string>();
    vec->push_back("1");
    vec->push_back("2");
    vec->push_back("3");
    vec->push_back("4");
    vec->push_back("5");


    cout << VectorUtils::toString<string>(*vec) << endl;

    delete vec;
}

static void testDeleteFast()
{
    std::cout << "Hello, world!" << std::endl;

    std::vector<int>* vec = new std::vector<int>();
    vec->push_back(1);
    vec->push_back(2);
    vec->push_back(3);
    vec->push_back(4);
    vec->push_back(5);

    //StdOut::out(std::to_string(vec->at(6)));

    VectorUtils::deleteFast(*vec, vec->begin()+1);

    for (int i = 0; i < vec->size(); i++)
        StdOut::out(std::to_string(vec->at(i)));


    delete vec;
}

static void someFunc2(vector<string>& args)
{
    cout << "executing some function" << endl;
    cout << "args=" << VectorUtils::toString(args) << endl;
}


static int testSimpleMenu()
{



    std::ifstream t("/home/tim/Development/UltiScanTastic/Scanner/bin/Debug/scannerBanner.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();

    SimpleMenu menu(buffer.str());

    menu.addOption(new MenuItemFunctionPointer("name", "desc", "info", someFunc ));
    menu.addOption(new MenuItemFunctionPointer("name2", "desc2", "info2", Testing::someFunc2 ));



    struct TestMenuItem : public MenuItemVirtual
    {
        void execute(vector<string>& args)
        {
            cout << "executing TestMenuItem!" << endl;
        }
        TestMenuItem(string n, string d, string i) : MenuItemVirtual(n,d,i) {};
    };

    menu.addOption(new TestMenuItem("n2", "d2", "i2") );


    menu.present();


    return 0;
}

static int testMenuFactory()
{



    std::ifstream t("/home/tim/Development/UltiScanTastic/Scanner/bin/Debug/scannerBanner.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();

    MenuFactory fac(buffer.str());

    fac.addOption(new MenuItemFunctionPointer("name", "desc", "info", [&] (vector<string>& args ) -> void { cout << "executing!" << endl; }  ));

    SimpleMenu* menu = fac.create();
    menu->present();

    delete menu;

    return 0;
}



    protected:
    private:
};


int main2()
{
    //Testing::testSplit();
    //Testing::testSplitRegex();

    Testing::testMenuFactory();
}

#endif // TESTING_H
