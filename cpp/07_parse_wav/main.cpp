#include <iostream>
#include <fstream>
#include "Parse.h"

int openFiles(int argc, char* argv[], std::ifstream* ifs, std::ofstream* ofs);

int main(int argc, char* argv[])
{
    std::ifstream ifs;
    std::ofstream ofs;

    switch(argc)
    {
        //not enough args
        case 0:case 1:
        {
            std::cout << "Need to specify input file!\n";
            return argc+1;
        }
        case 2:
        {
            ifs.open(argv[1]);
            ofs.open("out.txt");
            break;
        }
        case 3:
        {
            ifs.open(argv[1]);
            ofs.open(argv[2]);
            break;
        }
        default:
        {
            std::cout << "./wp <input file> <output file>\n";
            return -1;
        }
    }

    Parse parse(&ifs, &ofs);
    parse.interpret();
    std::string s;
    ifs >> s;
    std::cout << s;

    ifs.close();
    ofs.close();
    return 0;
}

int openFiles(int argc, char* argv[], std::ifstream* ifs, std::ofstream* ofs)
{

    return 0;
}

