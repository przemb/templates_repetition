#include <iostream>

// Generic versions of functions before templates

// C-style psudo-function using #define
#define MAX(a, b) ((a > b) ? (a) : (b))

// C++ overloaded functions
int max(int a, int b) {
    return (a > b) ? a : b;
}

double max(double a, double b) {
    return (a > b) ? a : b;
}

int* max(int* a_ptr, int* b_ptr) {
    return (*a_ptr > *b_ptr) ? a_ptr : b_ptr;
}

int main() {
    int a = 3, b = 4;

    // Using macros
    std::cout << "MAX(3, 4) = " << MAX(a, b) << "\n";

    // problem spotted!
    std::cout << "MAX(++a, ++b) = " << MAX(++a, ++b) << "\n"; 

    int x = 1, y = 2;
    std::cout << "MAX(x++, y++) = " << MAX(x++, y++) << "\n"; 
    std::cout << "x = " << x << ", y = " << y << "\n\n";

    // Using overloaded functions:
    std::cout << "max(5, 6) = " << max(5, 6) << "\n";
    std::cout << "max(7.7, 4.1) = " << max(7.7, 4.1) << "\n";
    std::cout << "*max(&x, &y) = " << *max(&x, &y) << "\n";

    return 0;
}