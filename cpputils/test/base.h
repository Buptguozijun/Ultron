/*
 * @Descripttion:
 * @version:
 * @Author: guozijun
 * @Date: 2020-03-12 06:51:03
 * @LastEditors: guozijun
 * @LastEditTime: 2020-06-27 16:34:48
 */
#pragma once

#include <iostream>

namespace cpputils {

class Base {
public:
  virtual ~Base() {};
  virtual void func();

};

class Derive : public Base {
public: 
  virtual void func() {
  std::cout<<" this is derive func" <<std::endl;
}

};
}  // namespace cpputils
