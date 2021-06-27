#include <iostream>

template <typename T>
class Base {
public:
    void do_it() {
        static_cast<T*>(this)->func();
    }
};

class Derived : public Base<Derived> {
public:
    void func() {
        std::cout << "Derived::func \n";
    }
};

int main() {
    std::cout << "CRTP\n";

    Derived d;
    d.do_it();

    return 0;
}