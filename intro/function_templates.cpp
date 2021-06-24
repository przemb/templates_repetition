#include <iostream>

// simple function templates

template <class T>
T max(const T& a, const T& b) {
    std::cout << "generic version, result: ";
    return (a > b) ? a : b;
}

int max(const int& a, const int& b) {
    std::cout << "int version, result: ";
    return (a > b) ? a : b;
}

int main() {
    int a = 3, b = 4;

    std::cout << "max(3, 5) = "     << max(3, 5) << "\n";
    std::cout << "max(2.4, 5.7) = " << max(2.4, 5.7) << "\n";    

    // this will generate a warning about implicit conversion
    // If you comment out the "int version" you will get an error
    // because of two parameter types aren't the same
    std::cout << "max(2, 8.7) = " << max(2, 8.7) << "\n"; 

    // this will force generation of double version
    std::cout << "max(2.0, 8) = " << max<double>(2.0, 8) << "\n"; 

    unsigned int i = 3;
    std::cout << "max(i, 6) = " << max(i, 6) << "\n";

    return 0;
}