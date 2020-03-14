/*
 * @Descripttion:
 * @version:
 * @Author: guozijun
 * @Date: 2020-03-12 06:51:03
 * @LastEditors: guozijun
 * @LastEditTime: 2020-03-14 06:28:33
 */
#pragma once

#include <cstdint>
#include <vector>
#include <unordered_map>
#include "common.h"
#include <list>

namespace cpputils {

template <typename Key, typename Value>
class LRU {
  typedef typename std::list<std::pair<Key, Value>>::iterator ListIter;

 public:
  LRU(size_t size) {
    size_ = size;
    kvs_.reserve(size);
  }

  ~LRU(){};

  void set(Key& key, Value& value) {
    std::pair<Key, Value> temp_pair = std::make_pair(key, value);
    if (kvs_.find(key) != kvs_.end()) {
      auto iter = kvs_[key];
      keys_.erase(iter);
      kvs_.erase(key);
    }
    if (kvs_.size() == size_) {
      auto temp_pair = keys_.back();
      keys_.pop_back();
      kvs_.erase(temp_pair.first);
    }
    keys_.push_front(temp_pair);
    kvs_[key] = keys_.begin();
  }

  bool get(Key& key, Value& value) {
    if (kvs_.find(key) == kvs_.end()) {
      return false;
    }
    auto& temp_pair = kvs_[key];
    value = temp_pair->second;
    moveToHead(temp_pair);
    std::cout << "value is: " << value << std::endl;
    return true;
  }

  void clear() {
    kvs_.clear();
    kvs_.reserve(size_);
    keys_.clear();
  }

  size_t size() {
    return kvs_.size();
  }

  size_t capacity() {
    return size_;
  }

  void print() const {
    for (auto pair : keys_) {
      std::cout << pair.first << " " << pair.second << std::endl;
    }
  }

 private:
  void moveToHead(ListIter& iter) {
    keys_.erase(iter);
    keys_.push_front(*iter);
  }

  size_t size_;
  std::list<std::pair<Key, Value>> keys_;
  std::unordered_map<Key, ListIter> kvs_;
};

}  // namespace cpputils
