#include <iostream>
#include <type_traits>
#include <cassert>

// type trait to determine whether a type is character
template <typename T>
struct is_char {
    static const bool value = false;
};

template<>
struct is_char<char> {
    static const bool value = true;
};

template<>
struct is_char<wchar_t> {
    static const bool value = true;
};

template<>
struct is_char<const char*> {
    static const bool value = true;
};

// side note:
//      decltype(data)::foo;

// A simple function that uses the trait
template <typename T>
void char_checker(T input) {
    if (is_char<T>::value)
        std::cout << "valid char! \n";
    else
        std::cout << "invalid char! \n";
}

template <typename T>
void integral_checker(T input) {
    if (std::is_integral<T>::value)
        std::cout << "it is integral! \n";
    else
        std::cout << "it is not integral \n";
}

template <typename T>
class Test {
    T value_;
public:
    Test(T val) : value_ {val} {
        std::cout << "std::is_integral<T>::value "
                  << std::is_integral<T>::value << "\n";
    }
};

int main() {
    std::cout << "Type traits \n";

    char_checker('c');
    char_checker(1);
    char_checker("c");
    std::cout << "----------- \n";

    Test<int>(1);
    Test<int>(1.0);

    Test<double>(2.0);
    Test<double>(2);

    std::cout << "----------- \n";
    integral_checker(1);
    integral_checker(1.0);

    return 0;
}