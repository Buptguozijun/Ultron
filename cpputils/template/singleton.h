/*
 * @Descripttion:
 * @version:
 * @Author: guozijun
 * @Date: 2020-03-17 02:31:35
 * @LastEditors: guozijun
 * @LastEditTime: 2020-03-17 07:11:01
 */

#pragma once

#include <memory>
#include <mutex>
namespace cpputils {
template <typename T>
class Singleton {
 public:
  template <typename... Args>
  static std::shared_ptr<T> getInstance(Args&&... args) {
    if (!instance_) {
      std::lock_guard<std::mutex> guard(mtx_);
      if (!instance_) {
        instance_ = std::make_shared<T>(std::forward<Args>(args)...);
      }
    }
    return instance_;
  }

 private:
  explicit Singleton();
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  static std::shared_ptr<T> instance_;
  static std::mutex mtx_;
};

template <typename T>
std::shared_ptr<T> Singleton<T>::instance_ = nullptr;

template <typename T>
std::mutex Singleton<T>::mtx_;
}  // namespace cpputils