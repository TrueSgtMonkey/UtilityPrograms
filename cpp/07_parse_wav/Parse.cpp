#include "Parse.h"

Parse::Parse(std::istream* is, std::ostream* os)
{
    this->is = is;
    this->os = os;
    s = "";
    num = 0;
}

void Parse::interpret()
{
    while(*is >> s)
    {
        for(int i = 0; i < s.size(); i++)
        {
            num = s[i];
            *os << "[" << num << "]";
        }
        *os << "\n";
    }
}
