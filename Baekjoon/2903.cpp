#include <iostream>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    std::cout << (long)std::pow((long)std::pow(2, N) + 1, 2) << std::endl;
    return 0;
}