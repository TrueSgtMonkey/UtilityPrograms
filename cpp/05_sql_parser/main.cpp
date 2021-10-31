#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "System.h"

int main()
{
    System sys((std::string) "sqlite3");
    sys.execute();

    sys.setExe(".open test.db");
    sys.execute();

    sys.setExe("CREATE TABLE ass (id NUMBER PRIMARY KEY, name TEXT);");
    sys.execute();

    sys.setExe(".quit");
    sys.execute();

    return 0;
}


