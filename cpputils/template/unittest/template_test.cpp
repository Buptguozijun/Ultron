/*
 * @Descripttion:
 * @version:
 * @Author: guozijun
 * @Date: 2020-03-13 07:01:33
 * @LastEditors: guozijun
 * @LastEditTime: 2020-06-27 21:55:27
 */

#include <iostream>
#include <string>
#include "../singleton.h"

class Calc{
public:
    Calc(int32_t n=0) {
      number = n;
    }
    void add() {
      number++;
      print();
    }
    void print() {
      std::cout<<" num is : "<< number <<std::endl;
    }
private:
    int32_t number;
};

int main() {
  std::cout<<" hello singleton" << std::endl;
  ::cpputils::Singleton<Calc>::Instance(1)->print();
  ::cpputils::Singleton<Calc>::Instance(2)->add();

  return 1;
}