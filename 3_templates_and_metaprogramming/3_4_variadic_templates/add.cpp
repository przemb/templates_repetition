#include <iostream>

// template <typename... Args>
// void func(Args... args) {
//
// }

// template <typename T1, typename T2, typename T3>
// void func(T1 arg1, T2 arg2, T3 arg3) {
// //...
// }

// -----------------

template <typename T>
T add(T value) {
    return value;
}

template <typename T, typename... Args>
T add(T value, Args... args) {
    return value + add(args...);
}

int main() {
    std::cout << "Variadic templates example \n";

    // test add function
    std::cout << add(1, 2, 3, 4) << "\n";
    return 0;
}
