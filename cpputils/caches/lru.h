#pragma once

#include <cstdint>
#include <vector>
#include <unordered_map>

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
    void update(int32_t key);
    size_t size_;
    // kvs_ 存放key value对
    std::unordered_map<int32_t, int32_t> kvs_;
    // keys 用于存放LRU的顺序
    std::vector<int32_t> keys_;

};

} // namespace cpputils
