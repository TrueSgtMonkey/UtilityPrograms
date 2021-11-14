#include <iostream>
#include "System.h"
#include <fstream>

int main(int argc, const char* argv[])
{
    switch(argc)
    {
        case 0:case 1:
        {
            std::cout << "Must specify directory!\n";
            return 1;
        }
        case 2:
        {
            std::cout << "Must specify project name!\n";
            return 2;
        }
    }
    
    //const char* can be given to strings!
    std::string directory = argv[1];
    std::string projectName = argv[2];

    //making directory that we will place main.cpp file into and makefile
    System mkdir("mkdir " + directory);
    //System touch("touch " + directory + "/" + "main.cpp");

    mkdir.execute();
    //touch.execute();
    std::ofstream m;
    m.open(directory + "/main.c");
    m << "#include <stdio.h>\n\n";
    m << "int main()\n" << "{\n" << "    ";
    m << "printf(\"Hello, World!\\n\");\n";
    m << "    return 0;\n}";
    m.close();

    std::string makefile = "SOURCES := $(wildcard *.c)\n";
    makefile += "OBJECTS := $(patsubst %.c,%.o,$(SOURCES))\n";
    makefile += "DEPENDS := $(patsubst %.c,%.d,$(SOURCES))\n\n";
    makefile += "# ADD MORE WARNINGS!\n";
    makefile += "WARNING := -Wall -Wextra\n\n";
    makefile += "# .PHONY means these rules get executed even if\n";
    makefile += "# files of those names exist.\n";
    makefile += ".PHONY: all clean\n\n";

    makefile += "# The first rule is the default, ie. \"make\",\n";
    makefile += "# \"make all\" and \"make parking\" mean the same\n";
    makefile += "all: " + projectName + "\n\n";
    makefile += "clean:\n";
    makefile += "\t$(RM) $(OBJECTS) $(DEPENDS) " + projectName + "\n\n";
    makefile += "#Linking exe from object files\n";
    makefile += projectName + ": $(OBJECTS)\n";
    makefile += "\t$(CXX) $(WARNING) $(CXXFLAGS) $^ -o $@\n\n"; 
    makefile += "-include $(DEPENDS)\n\n";
    makefile += "%.o: %.c Makefile\n";
    makefile += "\t$(CXX) $(WARNING) $(CXXFLAGS) -MMD -MP -c $< -o $@\n";
    
    std::ofstream ofs; 
    ofs.open(directory + "/makefile");
    ofs << makefile;
    ofs.close();

    return 0;
}
