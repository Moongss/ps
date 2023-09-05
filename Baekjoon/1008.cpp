#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << std::fixed;
    std::cout.precision(9);
    std::cout << (double) a * 1.0f / b  << std::endl;
    return (0);
}