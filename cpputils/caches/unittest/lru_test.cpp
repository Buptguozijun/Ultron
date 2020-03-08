#include <iostream>
#include "../lru.h"
#include <cassert>

int main() {
    std::cout<<" hello unittest"<<std::endl;
    cpputils::LRU lru(3);
    int32_t value=0;
    assert(lru.size() == 3);
    std::cout<<"construct ok"<<std::endl;

    lru.set(5, 4);
    lru.get(5, value);
    assert(value == 4);
    std::cout<<"get value == set value"<<std::endl;

    lru.set(2, 3);
    lru.set(1, 4);
    std::cout<<"lru size is: "<< lru.size()<<std::endl;
    lru.set(3, 4);
    assert(lru.get(5, value) == false);
    std::cout<<"expel lru ok"<<std::endl;
    // get 提位
    lru.get(2, value);
    lru.set(5, 4);
    assert(lru.get(1, value) == false);
    assert(lru.get(2, value) == true);
    std::cout<<"get reset lru ok"<<std::endl;
    // set 提位 5 2 3
    lru.set(3, 4);
    lru.set(1, 3);
    assert(lru.get(2, value) == false);
    std::cout<<"set reset lru ok"<<std::endl;


}
