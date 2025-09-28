#include "decimal.h"
#include <string>
#include <iostream>
#include <algorithm>

Decimal::Decimal() {}

Decimal::Decimal(const std::string& str) {
    for (int i = str.length() - 1; i >= 0; --i) {
        int digit = str[i] - '0';
        digits_.push_back(digit);
    }
}

Decimal::Decimal(const Decimal& other) : digits_(other.digits_) {
}

void Decimal::print() const {
    if (digits_.size() == 0) {
        std::cout << 0;
        return;
    }
    for (int i = digits_.size() - 1; i >= 0; --i) {
        std::cout << (int)digits_.get(i);
    }
}

void Decimal::push_back(unsigned char element) {
    digits_.push_back(element);
}

void Decimal::pop_back() {
    digits_.pop_back();
}

size_t Decimal::get_size() const {
    return digits_.size();
}

unsigned char Decimal::get_digit(size_t index) const {
    return digits_.get(index);
}

bool equals(const Decimal& a, const Decimal& b) {
    if (a.get_size() != b.get_size()) {
        return false;
    }
    for (size_t i = 0; i < a.get_size(); ++i) {
        if (a.get_digit(i) != b.get_digit(i)) {
            return false;
        }
    }
    return true;
}

bool greater(const Decimal& a, const Decimal& b) {
    if (a.get_size() != b.get_size()) {
        return a.get_size() > b.get_size();
    }
    for (int i = a.get_size() - 1; i >= 0; --i) {
        if (a.get_digit(i) > b.get_digit(i)) {
            return true;
        }
        if (a.get_digit(i) < b.get_digit(i)) {
            return false;
        }
    }
    return false;
}

bool less(const Decimal& a, const Decimal& b) {
    return !greater(a, b) && !equals(a, b);
}

Decimal plus(const Decimal& a, const Decimal& b) {
    int carry = 0;
    Decimal result;
    size_t min_len = std::min(a.get_size(), b.get_size());
    size_t max_len = std::max(a.get_size(), b.get_size());
    
    for (size_t i = 0; i < min_len; ++i) {
        int sum = a.get_digit(i) + b.get_digit(i) + carry;
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    
    for (size_t i = min_len; i < max_len; ++i) {
        int sum;
        if (a.get_size() > b.get_size()) {
            sum = a.get_digit(i) + carry;
        } else {
            sum = b.get_digit(i) + carry;
        }
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    
    if (carry > 0) {
        result.push_back(carry);
    }
    
    return result;
}

Decimal sub(const Decimal& a, const Decimal& b) {
    if (less(a, b)) {
        return Decimal("0");
    }
    if (equals(a, b)) {
        return Decimal("0");
    }

    Decimal result;
    int borrow = 0;

    for (size_t i = 0; i < b.get_size(); ++i) {
        int diff = a.get_digit(i) - b.get_digit(i) - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff);
    }

    for (size_t i = b.get_size(); i < a.get_size(); ++i) {
        int diff = a.get_digit(i) - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff);
    }

    while (result.get_digit(result.get_size() - 1) == 0 && result.get_size() > 1) {
        result.pop_back();
    }
    
    return result;
}