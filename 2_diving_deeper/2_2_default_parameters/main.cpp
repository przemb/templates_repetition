#include <iostream>
#include "stack.hpp"

int main() {
    std::cout << "Default parameters\n";

    Stack<int, 20> s20;
    Stack<float> s10;
    Stack<> s10a;

    s10a.push(5);
    s10a.push(10);
    s10a.push(15);

    std::cout << s10a.top() << "\n";
    s10a.pop();
    std::cout << s10a.top() << "\n";

    return 0;
}