#include <iostream>
#include "array.hpp"

template<typename T>
class Base {
protected:
    T prot_;
public:
    Base() : prot_{} {}
};

template<typename T>
class Derived : public Base<T> {
public:
    void print() { std::cout << this->prot_ << "\n"; }
};

int main() {
    std::cout << "Template inheritance \n";

    Derived<int> d;
    d.print();

    return 0;
}