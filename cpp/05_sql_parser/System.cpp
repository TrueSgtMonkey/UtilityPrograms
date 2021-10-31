#include "System.h"

System::System(char* message)
{
    exe = message;
}

System::System(std::string exe)
{
    this->exe = new char[exe.size()];
    for(int i = 0; i < exe.size(); i++)
    {
        this->exe[i] = exe[i];
    }
}

System::~System()
{
    delete[] exe;
}

int System::execute()
{
    return system(exe);    
}

int System::execute(std::string exe)
{
    char c[exe.size()];
    for(int i = 0; i < exe.size(); i++)
    {
        c[i] = exe[i];
    }
    return system(c);
}

int System::execute(char* exe)
{
    return system(exe);
}

void System::setExe(std::string message)
{
    char* c = new char[message.size()];
    for(int i = 0; i < message.size(); i++)
    {
        c[i] = message[i];
    }
    delete[] exe;
    exe = c;
}

char* System::getExe()
{
    return exe;
}
