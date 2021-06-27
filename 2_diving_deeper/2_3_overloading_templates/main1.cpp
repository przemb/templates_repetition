#include <iostream>
#include <cstring>

// function template
template <typename T>
const T& max(const T& a, const T& b) {
    std::cout << "Plain template\n";
    return (a > b) ? a : b;
}

// overload for three parameters
template <typename T>
const T& max(const T& a, const T& b, const T& c) {
    const T& tmp = (a > b) ? a : b;
    return (c > tmp) ? c : tmp;
}

// overload for pointers
template <typename T>
const T* max(const T* a, const T* b) {
    std::cout << "Pointer template\n";
    return (*a > *b) ? a : b;
}

// overload for strings
const char* max(const char* a, const char* b) {
    std::cout << "string template\n";
    return (std::strcmp(a, b) > 0) ? a : b;
}

// plain int version that will be used when conversion is needded
int max(int a, int b) {
    std::cout << "int version\n";
    return (a > b) ? a : b;
}

int main() {
    int n = max(3, 4);
    double d = max(2.3, 3.4);

    std::cout << "Test max(a, b, c)\n";
    std::cout << "max(5, 4, 7) = " << max(5, 4, 7) << "\n";

    std::cout << "Test pointer overload -------------- \n";
    const int* pa = new int{5};
    const int* pb = new int{4};
    std::cout << "max(pa, pb) = " << *(max(pa, pb)) << "\n";

    std::cout << "Test char* ------------------------- \n";
    const char* a = "abe";
    const char* b = "abj";

    auto result = max(a, b);
    std::cout << result << "\n";

    return 0;
}