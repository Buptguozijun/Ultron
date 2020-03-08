#pragma once
#include <cstdint>

namespace cpputils {
struct NodeList {
    int32_t value;
    int32_t key;
    NodeList* next;
    NodeList* before;
};

}
