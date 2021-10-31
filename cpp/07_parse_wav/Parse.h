#ifndef INC_07_PARSE_WAV_PARSE_H
#define INC_07_PARSE_WAV_PARSE_H

#include <iostream>
#include <stdint.h>

class Parse
{
    public:
        Parse(std::istream* is, std::ostream* os);
        void interpret();
    private:
        std::istream* is;
        std::ostream* os;
        std::string s;
        uint32_t num;
};

#endif //INC_07_PARSE_WAV_PARSE_H
