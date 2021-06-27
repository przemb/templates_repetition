#include <iostream>

// overload resulution
template <typename T>
void f(T val) {
    std::cout << "f(T) \n";
}

template <typename T>
void f(T* val) {
    std::cout << "f(T*) \n";
}

int main() {
    std::cout << "More overloading \n";

    f(0);
    f((int*)0);
    f(nullptr);

    return 0;

}