/*
 * @Description: 多线程安全的模版单例
 * @Version: 2.0
 * @Autor: guoizjun
 * @Date: 2020-06-27 21:33:42
 * @LastEditors: guozijun
 * @LastEditTime: 2020-06-27 22:00:03
 */ 


#include <memory>
#include<mutex>
namespace cpputils {

template <typename T>
class Singleton {
private:
    Singleton() {};
    Singleton(const Singleton& ) = delete;
    Singleton& operator=(const Singleton&) = delete;
    ~Singleton();
public:
    template <typename... Args>
    static std::shared_ptr<T> Instance(Args... args) {
        if (instance_ == nullptr) {
            std::lock_guard<std::mutex> guard(mtx);
            if (instance_ == nullptr) {
                instance_ = std::make_shared<T>(std::forward<Args>(args)...);
            }
        }
        return instance_;
    }

private:
    static std::shared_ptr<T> instance_;
    static std::mutex mtx;
};

template<typename T>
std::shared_ptr<T> Singleton<T>::instance_ = nullptr;

template<typename T>
std::mutex Singleton<T>::mtx;


} // namespace cpputils