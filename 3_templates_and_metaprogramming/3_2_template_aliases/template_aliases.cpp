#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>
#include <ranges>

// simple aliases
typedef int myInt;
using myInt = int;

// function poiners
typedef void (*func)(int);
using func = void (*)(int);

// typedef doesn't work with templates
typedef std::map<int, std::string> MyMap;   // OK

// template <typename T>
// typedef std::map<int, T> MyMap;          // FAIL

// "using" with templates
template <typename T>
using ptr = T*;

// ----- filter example
template <typename Seq, typename Pred>
Seq filter_remove(Seq s, Pred p) {
    // use an alias
    // use value_type trait for the argument type
    using f = std::function<bool(typename Seq::value_type)>;

    Seq result;
    std::remove_copy_if(std::begin(s), std::end(s),
                        std::back_inserter(result),
                        std::not1(f(p))
                        );
    return result;
}

template <typename Seq, typename Pred>
Seq filter_alternative(Seq s, Pred predicate) {
    Seq result {};
    std::copy_if(std::begin(s), std::end(s), std::back_inserter(result),
                        predicate);
    return result;
}      


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& input) {
    for(const auto& e : input)
        os << e << " ";
    os << "\n";
    return os;
}

int main() {
    std::cout << "Type aliases example \n";

    ptr<int> p; // p is int*

    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8};

    // predicates
    std::function<bool(int)> is_even = [](int x){ return x % 2 == 0; };
    auto is_large = [](int x){ return x >= 5; };

    auto r_even = filter_remove(input, is_even);
    std::cout << r_even;

    auto r_even2 = filter_alternative(input, is_large);
    std::cout << r_even2;

    // composing filters
    std::cout << "Composing filters \n";
    auto r_large_even = filter_remove(filter_remove(input, is_even), is_large);
    std::cout << r_large_even;

    // new filter
    auto r_large_even_new = input | std::views::filter(is_large) | std::views::filter(is_even);
    std::cout << r_large_even;

    return 0;
}