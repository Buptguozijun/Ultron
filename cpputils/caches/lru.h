#pragma once

#include <cstdint>
#include <vector>
#include <unordered_map>
#include "common.h"
#include <list>

namespace cpputils {

class LRU {
public:
    LRU(size_t size);
    ~LRU(){};
    void set(int32_t key, int32_t value);
    bool get(int32_t key, int32_t& value);
    void clear();
    size_t size();
    size_t capacity();
    void print() const;
private:
    void moveToHead(std::list<std::pair<int32_t, int32_t>>::iterator& iter);

    size_t size_;
    std::list<std::pair<int32_t, int32_t>> keys_;
    std::unordered_map<int32_t, std::list<std::pair<int32_t, int32_t>>::iterator> kvs_;

};

} // namespace cpputils
