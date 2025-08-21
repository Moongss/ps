#include <iostream>

int N, M;

int main() {
    std::cin >> N >> M;

    if (M < N && N <= M * 2) {
        for (int i = 0; i <= M; i++) {
            int pattyNum = 2 * i + (M - i + 1);
            if (pattyNum == N) {
                std::cout << "YES" << std::endl;
                std::cout << i + 1 << std::endl;
                for (int j = 0; j < M - i; j++) {
                    std::cout << "ab";
                }
                std::cout << "a" << std::endl;
                for (int j = 0; j < i; j++) {
                    std::cout << "aba" << std::endl;
                }
                return 0;
            }
        }
    }
    std::cout << "NO" << std::endl;
    return 0;
}