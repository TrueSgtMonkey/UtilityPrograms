#include <iostream>
#include "System.h"

int main()
{
    int err = 0;
    while(err == 0)
    {
        std::cout << "arg: ";
        std::string input;
        std::getline(std::cin, input);
        System sys(input);
        err = sys.execute();
    }
    return 0;
}
