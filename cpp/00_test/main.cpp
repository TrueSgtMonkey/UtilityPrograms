#include <iostream>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    for(int i = 0; i < argc - 1; i++)
    {
        std::cout << argv[i+1] << "\n";
        system(argv[i+1]);
    }

    return 0;
}
