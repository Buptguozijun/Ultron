#include "lru.h"
#include <iostream>

namespace cpputils {

LRU::LRU(size_t size) {
    size_ = size;
    kvs_.reserve(size);
    head_ = nullptr;
    tail_ = nullptr;
}

void LRU::moveToHead(NodeList* node) {
    if (kvs_.size() == 0) {
        head_ = node;
        node->next = tail_;
        return;
    }
    if (node == head_) {
        return;
    }
    NodeList* next = node->next;
    NodeList* before = node->before;
    if (node == tail_) {
        before = tail_;
    }
    if (before != nullptr) {
        before->next = next;
    }
    if (next != nullptr) {
        next->before = before;
    }
    head_->before = node;
    node->next = head_;
    node->before = nullptr;
    head_ = node;
}

void LRU::set(int32_t key, int32_t value) {
    NodeList* node = nullptr;
    if (kvs_.find(key) != kvs_.end()) {
        node = kvs_[key];
        node->value = value;
        moveToHead(node);
        return;
    }
    if (kvs_.size() == size_) {
        tail_->key = key;
        tail_->value = value;
        moveToHead(tail_);
    } else {
        node = new NodeList();
        node->key = key;
        node->value = value;
        moveToHead(node);
        kvs_[key] = node;
        if (kvs_.size() == size_) {
            tail_ = node;
        }
    }
}

bool LRU::get(int32_t key, int32_t& value) {
    if (kvs_.find(key) == kvs_.end()) {
        return false;
    }
    NodeList* node = kvs_[key];
    value = node->value;
    moveToHead(node);
    return true;
}

size_t LRU::size() {
    return kvs_.size();
}

size_t LRU::capacity() {
    return size_;
}

void LRU::clear() {
    kvs_.clear();
    kvs_.reserve(size_);
}


} // namespace cpputils
