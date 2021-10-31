#ifndef SYSTEM_HEADER
#define SYSTEM_HEADER

#include <iostream>
#include <stdlib.h>

class System
{
    public:
        System(std::string message);
        System(char* message);
        ~System();
        int execute();
        int execute(std::string exe);
        int execute(char* c);
        void setExe(std::string message);
        char* getExe();
    private:
        char* exe;
};

#endif
