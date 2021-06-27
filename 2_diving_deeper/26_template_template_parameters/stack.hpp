#pragma once

#include <iostream>
#include <string>
#include <vector>

class StackException : public std::exception {
    std::string msg_;
public:
    StackException(const std::string& msg) : msg_{msg} {}
    const char* what() const noexcept override {
        return msg_.c_str();
    }
};


template <typename T,
          template<typename, typename> class C = std::vector> 
class Stack {
    C<T, std::allocator<T>> data_;
    // C - container
public:
    void push(const T& n) {
        data_.push_back(n);
    }

    T top() {
        if (data_.size() == 0)
            throw StackException("Empty stack");
        return data_.back();
    }

    void pop() {
        if (data_.size() == 0)
            throw StackException("Empty stack");
        
        data_.pop_back();
    }
};
