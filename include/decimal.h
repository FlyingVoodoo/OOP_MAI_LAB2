#pragma once
#include <string>
#include <initializer_list>
#include "Vector.h"

class Decimal {
private:
    MyVector digits_;

public:
    Decimal();
    Decimal(const std::string& str);
    Decimal(const Decimal& other);
    Decimal(Decimal&& other) noexcept;
    Decimal(std::initializer_list<unsigned char> init_list);
    
    void print() const;
    
    void push_back(unsigned char element);
    void pop_back();

    size_t get_size() const;
    unsigned char get_digit(size_t index) const;
};

Decimal plus(const Decimal& a, const Decimal& b);
Decimal sub(const Decimal& a, const Decimal& b);

bool less(const Decimal& a, const Decimal& b);
bool greater(const Decimal& a, const Decimal& b);
bool equals(const Decimal& a, const Decimal& b);