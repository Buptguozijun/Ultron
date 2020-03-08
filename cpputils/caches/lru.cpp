#include "lru.h"
#include <iostream>

namespace cpputils {

LRU::LRU(size_t size) {
    size_ = size;
    kvs_.reserve(size);
}

void LRU::moveToHead(std::list<std::pair<int32_t, int32_t>>::iterator& iter) {
    keys_.erase(iter);
    keys_.push_front(*iter);
}

void LRU::set(int32_t key, int32_t value) {
    std::pair<int32_t, int32_t> temp_pair = std::make_pair(key, value);
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

bool LRU::get(int32_t key, int32_t& value) {
    if (kvs_.find(key) == kvs_.end()) {
        return false;
    }
    auto& temp_pair = kvs_[key];
    value = temp_pair->second;
    moveToHead(temp_pair);
    std::cout<<"value is: "<< value<<std::endl;
    return true;
}

size_t LRU::size() {
    return kvs_.size();
}

size_t LRU::capacity() {
    return size_;
}

void LRU::clear() {
    kvs_.clear();
    kvs_.reserve(size_);
    keys_.clear();
}

void LRU::print() const {
    for (auto pair : keys_) {
        std::cout<<pair.first <<" " << pair.second<<std::endl;
    }
}

} // namespace cpputils
