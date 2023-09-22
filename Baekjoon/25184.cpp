#include <iostream>

int N;
int main() {
    std::cin >> N;

    int d = (N == 1) ? 1 : N / 2;
    for (int i = d; i >= 1; i--) {
        for (int j = i; j <= N; j += d) {
            std::cout << j << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}