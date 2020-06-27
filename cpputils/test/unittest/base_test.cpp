/*
 * @Descripttion:
 * @version:
 * @Author: guozijun
 * @Date: 2020-03-12 07:10:31
 * @LastEditors: guozijun
 * @LastEditTime: 2020-06-27 16:35:32
 */
#include <iostream>
#include "../base.h"

int main() {
  std::cout << "hello base test" << std::endl;
  ::cpputils::Base* b = new ::cpputils::Derive();
  b->func();
  delete b;

  return 1;
}
