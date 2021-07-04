#include <iostream>
#include <vector>
#include <memory>

struct Point {
    int x_;
    int y_;
    Point(int x, int y) : x_{x}, y_{y} {}
};

template <typename T, typename... Args>
std::unique_ptr<T> create(Args... args) {
    return std::make_unique<T>(args...);
}

int main() {
    std::cout << "object creation \n";
    std::vector<Point> vec;

    Point p1(3, 3);
    vec.push_back(p1);

    vec.emplace_back(2, 2);
    std::cout << "(" << vec[1].x_ << "," << vec[1].y_ << ") \n"; 

    auto p2 = create<Point>(10, 10);
    std::cout << "(" << p2->x_ << "," << p2->y_ << ") \n";

    // won't compile
    // auto p3 = create<Point>(10);

    // won't compile
    // auto p3 = create<Point>(5, 5, 5);

    return 0;
}