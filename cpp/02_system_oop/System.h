#include <iostream>
#include <stdlib.h>

class System
{
    public:
        System(std::string message);
        int execute();
        int execute(std::string exe);
        void setExe(std::string message);
        char* getExe();
    private:
        char* exe;
};
