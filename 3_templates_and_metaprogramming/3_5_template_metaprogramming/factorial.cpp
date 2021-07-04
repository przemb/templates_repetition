#include <iostream>
#include <type_traits>

// based on enum
template <int N>
struct Fact {
    enum { value = N * Fact<N-1>::value };
};

template<>
struct Fact<0> {
    enum { value = 1 };
};

// based on constexpr
template <int N, typename T = int>
struct FactNew {
    static_assert(std::is_integral_v<T>,
                  "Type must be integer! \n");
    
    static constexpr T value = N * FactNew<N-1, T>::value;
};

template <typename T>
struct FactNew<0, T> {
    static_assert(std::is_integral_v<T>,
                  "Type must be integer! \n");
    static constexpr T value = 1;
};


int main() {
    std::cout << "Metaprogramming \n";

    std::cout << Fact<5>::value << "\n";
    std::cout << FactNew<5>::value << "\n";

    return 0;
}