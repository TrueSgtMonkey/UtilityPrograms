#include <iostream>
#include <stdlib.h>
#include <fstream>

int createStrings(std::string& project, std::string& package, std::string& program,
                  std::string& compile, std::string& run, int argc, 
                  const char* argv[]);
void execute(const std::string&);
std::string getStr(const char*);

int main(int argc, const char* argv[])
{
  std::ofstream ofs;
  std::string project = "";
  std::string package = "";
  std::string program = "";
  std::string compile = "";
  std::string run = "";
  
  int test = createStrings(project, package, program, compile, run, argc, argv);
  
  if(test != 0)
    return test;

  execute("mkdir " + project);
  execute("mkdir " + project + "/" + package);

  ofs.open(project + "/" + package + "/" + program + ".java");
  ofs << "package " << package << ";\n" << std::endl;
  ofs << "public class " << program << std::endl;
  ofs << "{" << std::endl;
  ofs << "    public static void main(String args[])" << std::endl;
  ofs << "    {" << std::endl;
  ofs << "        System.out.println(\"Hello, World!\");" << std::endl;
  ofs << "    }" << std::endl;
  ofs << "}" << std::endl;
  ofs.close();

  ofs.open(project + "/" + compile);
  ofs << "javac " << package << "/*.java";
  ofs.close();

  ofs.open(project + "/" + run);
  ofs << "java " << package << "." << program;
  ofs.close();

  return 0;
}

void execute(const std::string& s)
{
  char c[s.size()+1];
  for(int i = 0; i < s.size(); i++)
    c[i] = s[i];
  c[s.size()] = '\0';
  system(c);
}

int createStrings(std::string& project, std::string& package, std::string& program,
                  std::string& compile, std::string& run, int argc, 
                  const char* argv[])
{
  switch(argc)
  {
    case 0: case 1:
    {
      std::cout << "Must specify <project> <directory> <program_name>" << std::endl;
      return 1;
      break;
    }
    case 2:
    {
      std::cout << "Must specify " << argv[1] << " <directory> <program_name>" << std::endl;
      return 2;
      break;
    }
    case 3:
    {
      std::cout << "Must specify " << argv[1] << " " << argv[2] << " <program_name>" << std::endl;
      return 3;
      break;
    }
    case 4:
    {
      project = getStr(argv[1]);
      package = getStr(argv[2]);
      program = getStr(argv[3]);
      compile = "compile.bat";
      run = "run.bat";
      break;
    }
    case 5:
    {
      project = getStr(argv[1]);
      package = getStr(argv[2]);
      program = getStr(argv[3]);
      compile = getStr(argv[4]);
      run = "run.bat";
      break;
    }
    default:
    {
      project = getStr(argv[1]);
      package = getStr(argv[2]);
      program = getStr(argv[3]);
      compile = getStr(argv[4]);
      run = getStr(argv[5]);
      break;
    }
  }

  return 0;
}

std::string getStr(const char* str)
{
  std::string s = "";
  int i = 0;
  while(str[i] != '\0')
  {
    s.push_back(str[i]);
    i++;
  }
  return s;
}