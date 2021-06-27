#include <iostream>
#include "stack.hpp"

template <typename T>
T max(T a, T b) {
    std::cout << "Template \n";
    return (a > b) ? a : b;
}

// force instantiation of a double version of max
template double max<double>(double a, double b);

// force instantiation of an int version of Stack
template class Stack<int>;

// force instantiation of one member
template double Stack<double>::top();

int main() {
    std::cout << "Explicit instantiation \n";

    return 0;
}