#include <iostream>
#include <type_traits>

template <typename T>
void integral_checker(T val) {
    static_assert(std::is_integral<T>::value,
                  "Not a integral type");
    std::cout << "Type is integer \n";
}

template <typename T>
void number_checker(T val) {
    static_assert(std::is_arithmetic_v<T>,  // C++17
                  "Not an arithmetic type");
    std::cout << "Type is arithmetic \n";
}

template <typename T>
class Data {
    static_assert(std::is_copy_constructible<T>::value,
                  "Need a copy constructible type");
};                 // does it have copy constructor
                   // check Test class

class Test {
public:
    Test() {}
    Test(const Test&) = delete;
};

int main() {
    std::cout << "Static assert example \n";

    integral_checker(1);
    // integral_checker(5.0); // FAIL

    number_checker(53.2);
    number_checker('c');
    // number_checker("sth");

    Data<int> d1;
    // Data<Test> d2;          // FAIL

    return 0;
}