#ifndef VECTORS_H
#define VECTORS_H

#include <vector>
#include "StdOut.h"
#include <stdexcept>


#include <iterator>
#include <sstream>

using namespace std;

class VectorUtils
{
    public:

/** delete element by moving the last element to its place (not order preserving!)  */
        template <typename T, typename A>
            static void deleteFast(vector<T, A>  &v, typename vector<T, A>::iterator it)
        {
            //StdOut::out("d3");
            if (it - v.begin() >= v.size())
                throw out_of_range ("VectorUtils::_M_range_check");

            *it = *(v.end()-1);
            v.resize(v.size()-1);
        }

        //template <typename T, typename A>
          //  static string toString(const vector<T, A>& in);

/** for example "[1,2,3]" */
    template <typename T, typename A>
    static string toString(const vector<T, A>& vec)
    {

        if (vec.empty())
            return "{}";

        std::ostringstream oss;

        oss.put('{');

        // Convert all but the last element to avoid a trailing ","
        std::copy(vec.begin(), vec.end()-1,
            std::ostream_iterator<T>(oss, ","));

        // Now add the last element with no delimiter
        oss << vec.back();

        oss.put('}');

        return oss.str();
    }
        //template <typename T>
          //  static string toString(const vector<T>& in);
    protected:
    private:
};

#endif // VECTORS_H
