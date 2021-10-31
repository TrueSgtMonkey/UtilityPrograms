#include <iostream>
#include <stdlib.h>

char* convString(std::string s);

/**
 *  argv[1] will be the name of the file that we are going to copy to 
 */
int main(int argc, const char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Need to specify <name>.docx\n";
    return -1;
  }

  std::string arg = argv[1];
  for(int i = 2; i < argc; i++)
  {
    std::string s = argv[i];
    arg += "_" + s;
  }
  arg = "cp -r /users/codythompson/progs/empty.docx " + arg + ".docx";
  char* c = convString(arg);

  system(c);

  delete[] c;

  return 0;
}

char* convString(std::string s)
{
  char* c = new char[s.size()];
  for(int i = 0; i < s.size(); i++)
  {
    c[i] = s[i];
  }
  return c;
}
