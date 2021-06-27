#include <iostream>
#include "updated_stack.hpp"

int main() {
    Stack<int, 10> s10;
    Stack<int, 20> s20;

    s10.push(1);
    s10.push(2);
    s10.push(3);

    std::cout << s10.top() << "\n";
    s10.pop();
    std::cout << s10.top() << "\n";


    return 0;
}