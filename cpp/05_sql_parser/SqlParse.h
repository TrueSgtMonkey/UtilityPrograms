#ifndef SQLPARSE_HEADER
#define SQLPARSE_HEADER

#include <iostream>
#include "System.h"

class SqlParse
{
    public:
        SqlParse(std::string sys);
        ~SqlParse();
        void execute();
    private:
        std::string exe;
        System* sys;
};

#endif
