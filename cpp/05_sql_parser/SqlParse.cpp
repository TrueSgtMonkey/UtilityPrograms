#include "SqlParse.h"

SqlParse::SqlParse(std::string sys)
{
    exe = sys;
    System* sysStart = new System(exe);
    this->sys = sysStart;
}

SqlParse::~SqlParse()
{
    delete sys;
}

void SqlParse::execute()
{
    
}
