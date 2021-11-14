#include "StringVec.h"

StringVec::StringVec()
{
  arr = new std::string[1];
  sz = 0;
  total_sz = 1;
}

StringVec::~StringVec()
{
  delete[] arr;
}

void StringVec::push(std::string& s)
{
  arr[sz] = s;
  sz++;
  if(sz >= total_sz)
  {
    resize();
  }
}

std::string StringVec::pop()
{
  std::string s = arr[sz];
  arr[sz] = nullptr;
  sz--;
  return s;
}

std::string StringVec::get(int idx) const
{
  return (idx < sz) ? arr[idx] : "";
}

std::string StringVec::operator [] (int idx)
{
  return (idx < sz) ? arr[idx] : "";
}

void StringVec::print(std::ostream* os, bool vecForm)
{
  if(vecForm)
    *os << "[";
  for(int i = 0; i < sz; i++)
  {
    *os << arr[i];
    if(vecForm && i < sz-1)
      *os << ", ";
  }
  if(vecForm)
    *os << "]\n";
}

int StringVec::size() const
{
  return sz;
}

int StringVec::total_size() const
{
  return total_sz;
}

void StringVec::resize()
{
  total_sz *= 2;
  std::string* newArr = new std::string[total_sz];
  for(int i = 0; i < sz; i++)
  {
    newArr[i] = arr[i];
  }
  delete[] arr;
  arr = newArr;
}
