/*
 * @Descripttion:
 * @version:
 * @Author: guozijun
 * @Date: 2020-03-12 07:10:31
 * @LastEditors: guozijun
 * @LastEditTime: 2020-03-14 06:13:54
 */
#include <iostream>
#include "../lru.h"

int main() {
  std::cout << "hello lru unittest 输入lru的size" << std::endl;
  std::string cmd;
  int size = 0;
  std::cin >> size;
  cpputils::LRU<int, int> lru(size);
  std::cout << " lru size is: " << lru.capacity() << std::endl;
  while (std::getline(std::cin, cmd)) {
    if (cmd == "set") {
      int key = 0;
      int value = 0;
      std::cin >> key >> value;
      lru.set(key, value);
    } else if (cmd == "get") {
      int key = 0;
      int value = 0;
      std::cin >> key;
      lru.get(key, value);
    } else if (cmd == "print") {
      lru.print();
    }
  }
  return 1;
}
