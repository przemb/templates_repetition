#include <iostream>
#include <string>
using namespace std::string_literals;

template <typename T, typename U>
class Pair {
    T a_;
    U b_;
public:
    // construct with default values for a and b
    Pair() : a_{}, b_{} { std::cout << "Template call \n"; }
    Pair(const T& a, const U& b) : a_{a}, b_{b} {
        std::cout << "Template call \n";
    }
    T first()  { return a_; }
    U second() { return b_; }
};

// partially specialized Pair class
template <typename U>
class Pair<std::string, U> {
    std::string a_;
    U b_;
public:
    Pair() : a_{}, b_{} { std::cout << "Specialization call \n"; }
    Pair(const std::string& a, const U& b) : a_{a}, b_{b} {
        std::cout << "Specialization call\n";
    }
    std::string first() { return a_; }
    U second()          { return b_; }
};

// specialization where both parameters are the same
template <typename T>
class Pair<T, T> {
    T a_;
    T b_;
public:
    Pair() : a_{}, b_{} { std::cout << "Pair<T, T> call\n"; }
    Pair(const T& a, const T& b) : a_{a}, b_{b} {
        std::cout << "Pair<T, T> call \n";
    } 
    T first()  { return a_; }
    T second() { return b_; }
};

// specialization with poiter as the first type
template <typename T, typename U>
class Pair<T*, U> {
    T* a_;
    U b_;
public:
    // construct with default values for a and b
    Pair() : a_{nullptr}, b_{} { std::cout << "Pair<T*, U> call \n"; }
    Pair(const T* a, const U& b) : a_{a}, b_{b} {
        std::cout << "Pair<T*, U> call \n";
    }
    const T first() const { return *a_; }
    U second() const { return b_; }
};

int main() {
    std::cout << "Partial specialization examples\n\n";

    Pair<int, double> p0(12, 23.2);
    std::cout << p0.first() << ", " << p0.second() << "\n\n";
    
    Pair p1(13, 24.2); // class template argument deduction
    std::cout << p1.first() << ", " << p1.second() << "\n\n";

    Pair<std::string, int> p2("ah", 1);
    std::cout << p2.first() << ", " << p2.second() << "\n\n";

    Pair p3("ah"s, 2); // string
    std::cout << p3.first() << ", " << p3.second() << "\n\n";

    Pair<const char*, int> p4("ah", 3); // const char
    std::cout << p4.first() << ", " << p4.second() << "\n\n";

    const int b = 7;
    Pair<const int*, double> p5 {&b, 9};
    std::cout << p5.first() << ", " << p5.second() << "\n\n";
    
    Pair p6 {7, 9}; // int, int 
    std::cout << p6.first() << ", " << p6.second() << "\n\n";

    // Pair p7 {"ah"s, "ah"s}; // ambigous

    return 0;
}