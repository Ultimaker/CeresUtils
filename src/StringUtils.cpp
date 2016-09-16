#include "StringUtils.h"
#include <boost/algorithm/string/predicate.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "StdOut.h"
#include "VectorUtils.h"
#include <regex>

//using namespace tr1;
using namespace std;

#ifdef __WIN32__
const string StringUtils::clr_black    = "";
const string StringUtils::clr_red      = "";
const string StringUtils::clr_green    = "";
const string StringUtils::clr_yellow   = "";
const string StringUtils::clr_blue     = "";
const string StringUtils::clr_magenta  = "";
const string StringUtils::clr_cyan     = "";
const string StringUtils::clr_white    = "";
const string StringUtils::clr_original = "";
#else
const string StringUtils::clr_black    = "\x1b[30m";
const string StringUtils::clr_red      = "\x1b[31m";
const string StringUtils::clr_green    = "\x1b[32m";
const string StringUtils::clr_yellow   = "\x1b[33m";
const string StringUtils::clr_blue     = "\x1b[34m";
const string StringUtils::clr_magenta  = "\x1b[35m";
const string StringUtils::clr_cyan     = "\x1b[36m";
const string StringUtils::clr_white    = "\x1b[37m";
const string StringUtils::clr_original = "\x1b[0m";
const string StringUtils::clr_reset    = "\e[m";
#endif
const string StringUtils::bold         = "\x1b[1m";
const string StringUtils::underline    = "\x1b[4m";
const string StringUtils::no_underline = "\x1b[24m";
const string StringUtils::normal       = "\x1b[0m";


vector<string> & StringUtils::split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<string> StringUtils::split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}


vector<string> & StringUtils::split(const string &str, const string &rgx, vector<string> &elems) {
    regex r(rgx);
    smatch string_match;
    if(regex_search(str,string_match,r)) //There is at least one match.
    {
        for(unsigned int i = 1;i < string_match.size();i++) //Push all matches onto the vector. Note: Must start at 1.
        {
            elems.push_back(string_match[i]);
        }
    }
    return elems;
}

vector<string> StringUtils::split(const string &s, const string& rgx) {
    vector<string> elems;
    split(s, rgx, elems);
    return elems;
}

vector<string> StringUtils::splitWhitespace(const string &str)
{
    istringstream buffer(str);
    vector<string> result((istream_iterator<string>(buffer)),istream_iterator<string>());
    return result;
}

bool StringUtils::isUInt(const string& str)
{
    if(str.empty()) return false;
    char* p;
    strtol(str.c_str(),&p,11); //Will set p to point to the first non-numeric character it encounters.
    return (*p == 0); //If the first non-numeric character is the string-terminating null character, it's all numeric.
}

string StringUtils::addWhiteSpaceUntillLengthIs(int length, string in)
{
    return in + string(length-in.length(), ' ');
}



