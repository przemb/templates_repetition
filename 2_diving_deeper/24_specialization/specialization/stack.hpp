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

template <typename T>
class Stack {
    T* data_;
    size_t size_;
    size_t current_size_;
public:
    Stack(size_t s) :   size_{s}, 
                        current_size_{0}, 
                        data_{new T[s]}
                        {}
    ~Stack() { delete [] data_; }
    void push(const T& n);
    T top();
    void pop();
};

template <typename T>
inline void Stack<T>::push(const T& n) {
    if (current_size_ == size_)
        throw StackException("Full stack");

    data_[current_size_] = n;
    ++current_size_;
}

template <typename T>
inline T Stack<T>::top() {
    if (current_size_ == 0)
        throw StackException("Empty stack");

    return data_[current_size_ - 1];
}

template <typename T>
inline void Stack<T>::pop() {
    if (current_size_ == 0)
        throw StackException("Empty stack");

    current_size_--;
}