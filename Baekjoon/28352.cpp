#include <iostream>

int N;

int main() {
    std::cin >> N;

    int result = 6;
    for (int i = 11; i <= N; i++)
        result *= i;
    std::cout << result << std::endl;
    return 0;
}