#include <iostream>
#include <array>
#include <tuple>
#include <cassert>
#include <memory>
#include <string>

class Foo {
public:
    Foo() { std::cout << "Foo::Foo() \n"; }
    ~Foo() { std::cout << "Foo::~Foo \n"; }
    void func() { std::cout << "Foo::func \n"; }
};

std::unique_ptr<Foo> do_it(std::unique_ptr<Foo> p) {
    p->func();
    return p;
}

int main() {
    std::cout << "New types examples \n";

    std::array<int, 3> arr { 1, 2, 3 };
    std::cout << arr[1] << "\n";

    std::tuple<int, std::string, double> t1 {3, "Hi!", 2.1};
    std::cout << std::get<1>(t1) << "\n";

    // --- smart pointers
    std::unique_ptr<Foo> p1 = std::make_unique<Foo>();
    auto p2 = do_it(std::move(p1));

    assert(p1 == nullptr);
    p2->func();

    return 0;
}