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
#else
const string StringUtils::clr_black    = "\x1b[30m";
const string StringUtils::clr_red      = "\x1b[31m";
const string StringUtils::clr_green    = "\x1b[32m";
const string StringUtils::clr_yellow   = "\x1b[33m";
const string StringUtils::clr_blue     = "\x1b[34m";
const string StringUtils::clr_magenta  = "\x1b[35m";
const string StringUtils::clr_cyan     = "\x1b[36m";
const string StringUtils::clr_white    = "\x1b[37m";
#endif


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


vector<string> & StringUtils::split(const string &str, const string& rgx, vector<string> &elems) {
    regex r(rgx);

    regex_token_iterator<string::const_iterator> i(str.begin(), str.end(), r, -1);

    // default constructor = end-of-sequence:
    regex_token_iterator<string::const_iterator> eos;

    while (i != eos)
    {
        elems.push_back(*i);
        i++;
    }
    return elems;
}

vector<string> StringUtils::split(const string &s, const string& rgx) {
    vector<string> elems;
    split(s, rgx, elems);
    return elems;
}

bool StringUtils::isUInt(const string& str)
{
    return regex_match(str, regex("\\-?[0-9]+"));
}

string StringUtils::addWhiteSpaceUntillLengthIs(int length, string in)
{
    return in + string(length-in.length(), ' ');
}



