#include <iostream>

template <typename T>
void swap(T& a, T& b) {
    T tmp = b;
    b = a;
    a = tmp;
}

template <typename T>
T sum(const T* array, const size_t& s) {
    T sum = 0;
    for(auto i = 0; i < s; ++i)
        sum += array[i];
    return sum;
}

int main() {
    std::cout << "Test swap() ------------- \n";

    int i = 0, j = 1;
    swap(i, j);
    std::cout << "i = " << i << ", j = " << j << "\n";

    const char* s1 = "hello";
    const char* s2 = "world";
    swap(s1, s2);
    std::cout << "s1 = " << s1 << ", s2 = " << s2 << "\n";

    std::cout << "Test sum() --------------- \n";
    int tab1[5] = {1, 2, 3, 4, 5};
    std::cout << "Sum of ints: " << sum(tab1, 5) << "\n";

    double tab2[5] = {1.1, 2.2, 3.3};
    std::cout << "Sum of doubles: " << sum(tab2, 3) << "\n";

    return 0;
}