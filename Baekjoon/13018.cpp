#include <iostream>

int main() {
    int N, K;
    std::cin >> N >> K;

    if (K == N) {
        std::cout << "Impossible";
    }
    else if (K + 1 == N) {
        for (int i = 1; i <= N; i++) {
            std::cout << i << " ";
        }
    } else {
        std::cout << K + 2 << " ";
        for (int i = 2; i <= K + 1; i++) {
            std::cout << i << " ";
        }
        for (int i = K + 3; i <= N; i++) {
            std::cout << i << " ";
        }
        std::cout << 1;
    }
    std::cout << std::endl;
    return 0;
}