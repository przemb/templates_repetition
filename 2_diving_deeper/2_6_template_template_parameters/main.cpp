#include <iostream>
#include "stack.hpp"
#include <deque>

int main() {
    std::cout << "Template Template Parameters \n\n";

    std::cout << "Stack<int> s \n";
    Stack<int> s;
    s.push(5);
    s.push(10);
    s.push(15);
    std::cout << s.top() << "\n";
    s.pop();
    std::cout << s.top() << "\n";

    std::cout << "Stack<int, std::deque> sd \n";
    Stack<int, std::deque> sd;
    sd.push(30);
    sd.push(40);
    sd.push(50);
    std::cout << sd.top() << "\n";
    sd.pop();
    std::cout << sd.top() << "\n";    

    return 0;
}