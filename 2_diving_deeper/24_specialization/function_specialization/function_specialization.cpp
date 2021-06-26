#include <iostream>

// base template 
template <typename T>
T max(T a, T b) {
    std::cout << "base template \n";
    return (a > b) ? a : b;
}

// specialization for int
template<>
int max(int a, int b) {
    std::cout << "int specialization \n";
    return (a > b) ? a : b;
}

// specialization for int*
template<>
int* max(int* a, int* b) {
    std::cout << "int* specialization \n";
    return (*a > *b) ? a : b;
}


int main() {
    std::cout << "Function specialization examples\n";

    std::cout << max(2.2, 3.3) << "\n";
    std::cout << max(4, 7) << "\n";
    auto a = 3, b = 7;
    std::cout << *max(&a, &b) << "\n";

    return 0;
}