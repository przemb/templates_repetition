#pragma once

#include <string>
#include <exception>

class StackException : public std::exception {
    std::string msg_;
public:
    StackException(const std::string& m) : msg_{m} {}
    const char* what() const noexcept override {
        return msg_.c_str();
    }
};

// size is defaulted to 10
template<typename T = int, int SIZE = 10>
class Stack {
    T data_[SIZE];
    size_t current_size_;
public:
    Stack() : current_size_{0} {}
    ~Stack() {};
    void push(const T& n);
    T top();
    void pop();
};

template<typename T, int SIZE>
inline void Stack<T, SIZE>::push(const T& n) {
    if (current_size_ == SIZE)
        throw StackException("Full stack");

    data_[current_size_] = n;
    ++current_size_;
}

template<typename T, int SIZE>
inline T Stack<T, SIZE>::top() {
    if (current_size_ == 0)
        throw StackException("Empty stack");
    
    return data_[current_size_ - 1];
}

template <typename T, int SIZE>
inline void Stack<T, SIZE>::pop() {
    if (current_size_ == 0)
        throw StackException("Empty stack");
    
    current_size_--;
}