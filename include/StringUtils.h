#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <vector>

using namespace std;

class StringUtils
{
    public:
        static vector<string> &split(const string &s, char delim, vector<string> &elems); //!< split string and put substrings in specified vector
        static vector<string> split(const string& in, char separator);
        static vector<string> &split(const string &s, const string& rgx, vector<string> &elems); //!< split string and put substrings in specified vector @param rgx regular expressions
        static vector<string> split(const string& in, const string& rgx); //!< @param rgx regular expressions
        /*!
         * \brief Splits a string by whitespace.
         *
         * This doesn't use regular expressions to split the string, so it will
         * often be faster and most importantly, be able to run in older MinGW
         * versions.
         *
         * \param str The string to split.
         */
        static vector<string> splitWhitespace(const string& in);

        static bool isUInt(const string& str);

        static const string clr_black;
        static const string clr_red;
        static const string clr_green;
        static const string clr_yellow;
        static const string clr_blue;
        static const string clr_magenta;
        static const string clr_cyan;
        static const string clr_white;
        static const string clr_original;

        static string addWhiteSpaceUntillLengthIs(int length, string in);//!< add white space after string
    protected:
    private:
};

#endif // STRINGUTILS_H
