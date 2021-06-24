#include <iostream>
#include <string>

class StackException : public std::exception {
    std::string msg_;
public:
    StackException(const std::string& m) 
    : msg_(m) {}
    
    const char* what() const noexcept override {
        return msg_.c_str();
    }
};

template <typename T>
class Stack {
    size_t size_;
    size_t current_occupancy_;
    T* data_;

public:
    Stack(size_t s) : size_{s}, current_occupancy_{0}, data_{new T[s]} {}
    ~Stack() {delete [] data_; }

    // "push" defined inline inside the class
    void push(const T& n) {
        if(current_occupancy_ == size_)
            throw StackException("Full stack");
        data_[current_occupancy_] = n;
        ++current_occupancy_;
    }
    T top();
    void pop();
};

// "top" explicitly defined inline outsude the class body
template <typename T>
inline T Stack<T>::top() {
    if (current_occupancy_ == 0)
        throw StackException("Empty stack");

    return data_[current_occupancy_-1];
}

template <typename T>
inline void Stack<T>::pop() {
    if (current_occupancy_ == 0)
        throw StackException("Empty stack");
    current_occupancy_--;
}

int main() {
    Stack<int> s(10);

    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << "My stack: \n";
    std::cout << s.top() << "\n";
    s.pop();
    std::cout << s.top() << "\n";

    return 0;
}