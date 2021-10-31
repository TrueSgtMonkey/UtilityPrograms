#include "TestClass.h"

TestClass::TestClass(std::string message)
{
    this->message = message;
}

void TestClass::print()
{
    std::cout << message;
}
