/*
 * @Descripttion:
 * @version:
 * @Author: guozijun
 * @Date: 2020-03-13 07:01:33
 * @LastEditors: guozijun
 * @LastEditTime: 2020-03-14 02:07:33
 */

#include <iostream>
#include <string>
#include "../template.h"

int main() {
  std::cout << "Hello templateV2" << std::endl;
  std::string cmd;
  int size = 0;
  std::cin >> size;
  cpputils::TemplateMap<std::string> lru(size);
  while (std::getline(std::cin, cmd)) {
    if (cmd == "set") {
      std::string key;
      std::string value;
      std::cin >> key >> value;
      lru.set(key, value);
    } else if (cmd == "get") {
      std::string key;
      std::string value;
      std::cin >> key;
      lru.get(key, value);
    } else if (cmd == "print") {
      lru.print();
    }
  }
  return 1;
}