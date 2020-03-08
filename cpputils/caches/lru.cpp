#include "lru.h"
#include <iostream>

namespace cpputils {

LRU::LRU(size_t size) {
    size_ = size;
    kvs_.reserve(size);
    keys_.reserve(size);
}

void LRU::set(int32_t key, int32_t value) {
    if (kvs_.find(key) != kvs_.end()) {
        update(key);
        kvs_[key] = value;
        return;
    }
    if (kvs_.size() == size_) {
        int32_t del_key = keys_.back();
        kvs_.erase(del_key);
        keys_.erase(keys_.end() -1);
    }
    kvs_[key] = value;
    keys_.insert(keys_.begin(), key);
    return;
}

bool LRU::get(int32_t key, int32_t& value) {
    if (kvs_.find(key) == kvs_.end()) {
        return false;
    }
    value = kvs_[key];
    update(key);
    return true;
}

void LRU::update(int32_t key) {
    auto iter = std::find(keys_.begin(), keys_.end(),
            key);
    keys_.erase(iter);
    keys_.insert(keys_.begin(), key);
}

size_t LRU::size() {
    return keys_.size() == kvs_.size()?
           keys_.size():-1;
}

size_t LRU::capacity() {
    return size_;
}

void LRU::clear() {
    kvs_.clear();
    keys_.clear();
    kvs_.reserve(size_);
    keys_.reserve(size_);
}

void LRU::print() const {
    if (keys_.size() != kvs_.size()) {
        std::cout<<"LRU ERROR"<<std::endl;
    }
    std::cout<<" key is: "<<std::endl;
    for (auto& key : keys_) {
        std::cout<<key<<" ";
    }
    std::cout<<" "<<std::endl;
    for (auto iter = kvs_.begin(); iter != kvs_.end(); iter++) {
        std::cout<<iter->first<<" "<< iter->second<<std::endl;
    }

}

}
