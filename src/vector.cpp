#include "Vector.h"
#include <stdexcept>
#include <algorithm>

MyVector::MyVector() : size_(0), capacity_(1), data_(new unsigned char[capacity_]) {}

MyVector::~MyVector() {
    delete[] data_;
}

MyVector::MyVector(const MyVector& other) : size_(other.size_), capacity_(other.capacity_), data_(new unsigned char[capacity_]) {
    std::copy(other.data_, other.data_ + size_, data_);
}

MyVector::MyVector(MyVector&& other) noexcept : size_(other.size_), capacity_(other.capacity_), data_(other.data_) {
    other.size_ = 0;
    other.capacity_ = 0;
    other.data_ = nullptr;
}

MyVector& MyVector::operator=(const MyVector& other) {
    if (this == &other) {
        return *this;
    }
    delete[] data_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new unsigned char[capacity_];
    std::copy(other.data_, other.data_ + size_, data_);
    return *this;
}

void MyVector::push_back(unsigned char element) {
    if (size_ >= capacity_) {
        resize(capacity_ * 2);
    }
    data_[size_++] = element;
}

void MyVector::pop_back() {
    if (size_ > 0) {
        size_--;
    }
}

unsigned char MyVector::get(size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of bounds");
    }
    return data_[index];
}

size_t MyVector::size() const {
    return size_;
}

void MyVector::clear() {
    size_ = 0;
}

// void MyVector::clear() {
//     delete[] data_;
//     data_ = new unsigned char[1];
//     size_ = 0;
//     capacity_ = 1;
// }

void MyVector::resize(size_t new_capacity) {
    unsigned char* new_data = new unsigned char[new_capacity];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}