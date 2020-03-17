/*
 * @Descripttion:
 * @version:
 * @Author: guozijun
 * @Date: 2020-03-13 07:01:33
 * @LastEditors: guozijun
 * @LastEditTime: 2020-03-17 07:18:13
 */

#include <iostream>
#include <string>
#include <assert.h>
#include "../singleton.h"

class Manager {
 public:
  Manager(int book) {
    book_ = book;
  }
  int getBook() {
    return book_;
  }

 private:
  int book_;
};
using managerSingleton = cpputils::Singleton<Manager>;
int main() {
  std::cout << "Hello templateV2" << std::endl;

  std::shared_ptr<Manager> manager_ = managerSingleton::getInstance(5);
  std::shared_ptr<Manager> manager_2 = managerSingleton::getInstance(6);
  assert(manager_->getBook() == manager_2->getBook());
  std::cout << "singleton test success" << std::endl;
  return 1;
}