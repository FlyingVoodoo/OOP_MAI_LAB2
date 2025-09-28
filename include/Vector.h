#pragma once
#include <iostream>

class MyVector {
private:
    size_t size_;
    size_t capacity_;
    unsigned char *data_;

    void resize(size_t new_capacity);

public:
    MyVector();
    ~MyVector();
    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other);

    void push_back(unsigned char element);
    void pop_back();

    unsigned char get(size_t index) const;
    size_t size() const;
    void clear();
};