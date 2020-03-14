/*
 * @Descripttion:
 * @version:
 * @Author: guozijun
 * @Date: 2020-03-13 06:58:12
 * @LastEditors: guozijun
 * @LastEditTime: 2020-03-14 02:06:29
 */

#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

namespace cpputils {

template <typename T>
class TemplateMap {
 public:
  TemplateMap(int size) {
    key_.reserve(size);
    value_.reserve(size);
  }
  void get(const T& key, T& value) {
    if (key_.find(key) == key_.end()) {
      std::cout << " Not find key" << std::endl;
    }
    std::cout << value_[key_[key]] << std::endl;
  }
  void set(const T& key, const T& value) {
    int index = value_.size();
    if (key_.find(key) != key_.end()) {
      index = key_[key];
    }
    value_[index] = value;
    key_[key] = index;
  }
  void print() {
    for (auto iter = key_.begin(); iter != key_.end(); iter++) {
      std::cout << iter->first << " " << value_[iter->second] << std::endl;
    }
  }

 private:
  std::unordered_map<T, int> key_;
  std::vector<T> value_;
};

}  // namespace cpputils