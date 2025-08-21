#include <iostream>

int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = N - i - 1; j > 0; j--) {
            std::cout << " ";
        }
        for (int j = 1; j <= 2 * i + 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << " ";
        }
        for (int j = (N - i - 1) * 2 - 1; j > 0; j--) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}