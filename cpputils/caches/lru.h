#pragma once

#include <cstdint>
#include <vector>
#include <unordered_map>
#include "common.h"

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
    void moveToHead(NodeList* node);

    size_t size_;
    NodeList* head_;
    NodeList* tail_;
    std::unordered_map<int32_t, NodeList*> kvs_;

};

} // namespace cpputils
