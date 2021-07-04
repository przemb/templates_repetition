#include <iostream>

void print() {
    // do nothing for no arguments
}

template <typename T, typename... Args>
void print(T head, Args... args) {
    std::cout << head << ' ';
    print(args...);
}

template <typename T, typename... Args>
void print_improved(T head, Args... args) {
    std::cout << head;
    if constexpr(sizeof...(args) > 0) {
        std::cout << ' ';
        print_improved(args...);
    }
}


int main() {
    std::cout << "Variadic print example \n";
    print("Let's", "check", "it", "n", 0, "w", "\n");
    std::cout << "\n";

    print_improved("impr", 0, 'v', 3, 'd', "version", "\n");

    return 0;
}