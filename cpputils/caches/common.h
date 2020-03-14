/*
 * @Descripttion:
 * @version:
 * @Author: guozijun
 * @Date: 2020-03-12 06:51:03
 * @LastEditors: guozijun
 * @LastEditTime: 2020-03-14 02:08:16
 */
#pragma once
#include <cstdint>

namespace cpputils {
struct NodeList {
  int32_t value;
  int32_t key;
  NodeList* next;
  NodeList* before;
};

}  // namespace cpputils
