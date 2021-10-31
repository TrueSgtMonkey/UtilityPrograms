#include <iostream>
#include <fstream>

int main()
{
    std::ifstream ifs;
    ifs.open("input.txt");

    ifs.close();
    return 0;
}
