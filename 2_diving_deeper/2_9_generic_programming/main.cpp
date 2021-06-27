#include <iostream>
#include <array>

template <typename T, typename Iterator>
Iterator find(T c, Iterator start, Iterator end) {
    while(start != end and *start != c)
        ++start;
    return start;
}

int main() {
    char str[] = "Hello, world!";
    char* end = str + sizeof(str);

    char* p = find(',', str, end);
    
    if (p != end)
        std::cout << p << "\n";

    std::cout << " ------- \n";

    int arr[] = {1, 2, 3, 4, 5};
    int* arr_end = arr + 5;
    
    int* arr_p = find(4, arr, arr_end);
    if (arr_p != arr_end)
        std::cout << *arr_p << "\n";

    std::cout << " ------ \n";

    std::array<int, 5> my_arr {1, 2, 6, 4, 5};
    int* result = find(6, my_arr.begin(), my_arr.end());
    if (result != my_arr.end())
        std::cout << *result << "\n";

    return 0;
}