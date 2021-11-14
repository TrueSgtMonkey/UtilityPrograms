#include <iostream>
#include <stdlib.h>

class System
{
    public:
        System(std::string message);
        ~System();
        int execute();
        void setExe(std::string message);
        char* getExe();
    private:
        char* exe;
};
