/*
 * @Descripttion:
 * @version:
 * @Author: guozijun
 * @Date: 2020-03-22 05:36:09
 * @LastEditors: guozijun
 * @LastEditTime: 2020-03-22 06:14:40
 */

#include <shared_mutex>
#include <memory>
#include <mutex>

namespace cpputils {
typedef std::shared_lock<std::shared_mutex> read_lock;
typedef std::unique_lock<std::shared_mutex> write_lock;

template <typename T>
class DynamicDict {
 public:
  DynamicDict(){};
  explicit DynamicDict(std::shared_ptr<T>& dict);
  std::shared_ptr<const T> GetDict();
  void Swap(std::shared_ptr<T>& dict);

  DynamicDict(const DynamicDict&) = delete;
  DynamicDict& operator=(const DynamicDict&) = delete;

 private:
  std::shared_ptr<T> dict_;
  mutable std::shared_mutex mutex_;
};

template <typename T>
std::shared_ptr<const T> DynamicDict<T>::GetDict() {
  read_lock(mutex_);
  return dict_;
}

template <typename T>
void DynamicDict<T>::Swap(std::shared_ptr<T>& dict) {
  write_lock(mutex_);
  dict_.swap(dict);
}

template <typename T>
DynamicDict<T>::DynamicDict(std::shared_ptr<T>& dict) {
  dict = dict_;
}

}  // namespace cpputils