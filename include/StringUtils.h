#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <vector>

using namespace std;

class StringUtils
{
    public:
        static vector<string> &split(const string &s, char delim, vector<string> &elems);
        static vector<string> split(const string& in, char separator);
        static vector<string> &split(const string &s, const string& rgx, vector<string> &elems);
        static vector<string> split(const string& in, const string& rgx);

        static bool isUInt(const string& str);

        static const string clrBlack;
        static const string clrRed;
        static const string clrGreen;
        static const string clrYellow;
        static const string clrBlue;
        static const string clrMagenta;
        static const string clrCyan;
        static const string clrWhite;

    protected:
    private:
};

#endif // STRINGUTILS_H
