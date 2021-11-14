#include <iostream>
#include <fstream>
#include "StringVec.h"
#include "System.h"

bool openInput(std::ifstream* ifs, const char* filename);
void executeProgs(StringVec& strvec);
int javacrun(std::ifstream& compile, std::ifstream& run, bool& debug, 
               int argc, const char* argv[]);
int javarun(std::ifstream& run, bool& debug, int argc, const char* argv[]);
void parseInput(std::ifstream& ifs, StringVec& strvec);

int main(int argc, const char* argv[])
{
  std::ifstream compile; // comment this out if only running
  std::ifstream run;
  bool debug = false;
  //run this to compile & run java files
  int test = javacrun(compile, run, debug, argc, argv); 
  //int test = javarun(run, debug, argc, argv); //run this to only run java files
  if(test != 0)
    return test;

  StringVec cI; // comment this out if only running
  StringVec rI;
  
  parseInput(compile, cI); // comment this out if only running
  parseInput(run, rI);

  if(debug)
  {
    cI.print(&std::cout); // comment this out if only running
    rI.print(&std::cout);
  }

  executeProgs(cI); // comment this out if only running
  executeProgs(rI);
  
  compile.close(); // comment this out if only running
  run.close();
  return 0;
}

void parseInput(std::ifstream& ifs, StringVec& strvec)
{
  std::string input;
  while(!(ifs.eof()))
  {
    std::getline(ifs, input);
    strvec.push(input);
  }
}

int javarun(std::ifstream& run, bool& debug, int argc, const char* argv[])
{
  switch(argc)
  {
    case 0: case 1:
    {
      if(!openInput(&run, "run.bat"))
      {
        return 1;
      }
      break;
    }
    default:
    {
      if(!openInput(&run, argv[1]))
        return 1;
      debug = true;
      break;
    }
  }
  return 0;
}

int javacrun(std::ifstream& compile, std::ifstream& run, bool& debug, 
               int argc, const char* argv[])
{
  switch(argc)
  {
    //no compile or run files given, looking for compile.bat and run.bat
    case 0: case 1:
    {
      if(!openInput(&compile, "compile.bat"))
      {
        return 1;
      }
      if(!openInput(&run, "run.bat"))
      {
        return 2;
      }
      break;
    }
    case 2:
    {
      if(!openInput(&compile, argv[1]))
      {
        return 1;
      }
      if(!openInput(&run, "run.bat"))
      {
        return 2;
      }
      break;
    }
    default:
    {
      if(!openInput(&compile, argv[1]))
      {
        return 1;
      }
      if(!openInput(&run, argv[2]))
      {
        return 2;
      }
      debug = (argc > 3) ? true : false;
      break;
    }
  }
  return 0;
}

bool openInput(std::ifstream* ifs, const char* filename)
{
  (*ifs).open(filename);
  if(!(*ifs).is_open())
  {
    std::cout << "Could not open " << filename << "\n";
    return false;
  }

  return true;
}

void executeProgs(StringVec& strvec)
{
  for(int i = 0; i < strvec.size(); i++)
  {
    char c[strvec[i].size()+1];
    for(int j = 0; j < strvec[i].size(); j++)
    {
      c[j] = strvec[i][j];
    }
    c[strvec[i].size()] = '\0';
    system((const char*)c);
  }
}


