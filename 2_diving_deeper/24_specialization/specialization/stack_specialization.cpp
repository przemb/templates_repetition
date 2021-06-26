#include <iostream>
#include <string>
#include "stack.hpp"

// stack specialized for std::string
template <>
class Stack<std::string> {
    std::string* data_;
    size_t size_;
    size_t current_size_; 
public:
    Stack(size_t s) :   size_{s}, 
                        current_size_{0}, 
                        data_{new std::string[s]} 
                        { std::cout << "String stack specialization \n"; }
    ~Stack() { delete [] data_; }

    void push(const std::string& n) {
        if (current_size_ == size_)
            throw StackException("Full stack\n");
   
        data_[current_size_] = n;
        ++current_size_;
    }
    
    std::string top();
    void pop();
};


// the "template<>" is not used when defining 
// a specialized member outside the body of the class
std::string Stack<std::string>::top() {
    if (current_size_ == 0)
        throw StackException("Empty stack");
    
    std::cout << "string top\n";
    return data_[current_size_ - 1];
}

void Stack<std::string>::pop() {
    if (current_size_ == 0)
        throw StackException("Empty stack!\n");
    
    --current_size_;
}

// a member function specialized for int
// this jut provides 'int' version,
// the rest will be generated...
// Unlike the full specialization,
// "template<>" is needed

template<>
int Stack<int>::top() {
    std::cout << "int top \n";
    if (current_size_ == 0)
        throw StackException("Empty stack");
    
    return data_[current_size_ - 1];
}

int main() {
    Stack<double> sd(10);
    sd.push(1.0);
    sd.top();

    std::cout << "Template specialization \n\n";

    Stack<std::string> ss(10);
    ss.push("one");
    ss.push("two");
    ss.push("thee");
    ss.top();

    Stack<int> si(10);
    si.push(1);
    si.top();

    return 0;
}