#include <iostream>

// ----- Require derivation
class Base {};

class Derived : public Base {};

class NotDerived {};

template <typename T>
void Foo(const T& obj) {
    static_assert(std::is_base_of_v<Base, T>,
                  "Type must inherit from Base");
}

// ---- Combining assertions

class Test {
public:
    Test() {}
    Test(const Test& t) {}
    Test& operator=(const Test& t) { return *this; }
};

class Test2 {
public:
    Test2(int ignore) {};
    Test2(const Test2& t) {}
};

template <typename T>
void Bar(T val) {
    static_assert(std::is_default_constructible_v<T> &&
                  std::is_copy_constructible_v<T>,
                  "T must be default and copy constructible");
}

// --- alternative

template <typename... Conds>
struct _and : std::true_type {
};

template <typename Cond, typename... Conds>
struct _and<Cond, Conds...> {
    static constexpr bool value = 
    std::conditional<Cond::value, _and<Conds...>, std::false_type>::type::value;
};

int main() {
    std::cout << "static assertions example \n";

    Derived d;
    NotDerived n;

    Foo(d);         // OK
    // Foo(n);      // FAIL

    Test t;
    Test2 t2(7);
    Bar(t);         // OK
    // Bar(t2);     // FAIL

    static_assert(_and<std::is_default_constructible<Test>,
                  std::is_copy_constructible<Test>,
                  std::is_copy_assignable<Test>>::value,
                  "Test is not OK");

    // Test2 does not have assignment operator
    // static_assert(_and<std::is_default_constructible<Test2>,
    //               std::is_copy_constructible<Test2>,
    //               std::is_copy_assignable<Test2>::value,
    //               "Test2 is not OK");

    return 0;
}