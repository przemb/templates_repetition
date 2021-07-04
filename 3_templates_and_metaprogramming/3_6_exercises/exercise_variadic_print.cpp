#include <iostream>

// basic
template <typename T>
void print(T val) {
    std::cout << val << "\n";
}

template <typename T, typename... Args>
void print(T head, Args... args) {
    std::cout << head << ' ';
    print(args...);
}

// extended
template <typename T, typename... Args>
void print_ext(T head, Args... args) {
    std::cout << head << ' ';
    if constexpr(sizeof...(args) > 0)
        print_ext(args...);
    else
        std::cout << "\n";
}

// fold
template <typename... Args>
void print_f(Args&&... args) {
    ((std::cout << args << ' '), ...) << '\n';
}


int main() {
    print(1, 2, "abc", 5);
    print_ext("keep", 5, "calm");
    print_f("high", "fiv", 3);

    return 0;
}