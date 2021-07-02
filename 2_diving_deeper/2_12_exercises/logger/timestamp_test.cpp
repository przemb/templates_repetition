#include <iostream>
#include <iomanip>
#include <chrono>

int main() {

    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::cout << std::put_time(localtime(&now), "%F %T");
    return 0;
}