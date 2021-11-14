//
// Created by Cody Thompson on 11/13/21.
//

#ifndef INC_01_JAVA_PRAC_STRINGVEC_H
#define INC_01_JAVA_PRAC_STRINGVEC_H

#include <iostream>

class StringVec
{
  public:
    StringVec();
    ~StringVec();
    void push(std::string&);
    std::string pop();
    std::string get(int idx) const;
    std::string operator [](int idx);
    int size() const;
    int total_size() const;
    void print(std::ostream*, bool vecForm = true);
  private:
    void resize();
    std::string* arr;
    int sz;
    int total_sz;
};

#endif //INC_01_JAVA_PRAC_STRINGVEC_H
