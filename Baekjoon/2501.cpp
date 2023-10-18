#include <iostream>

int main() {
    int N, K;
    std::cin >> N >> K;

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0)
            cnt++;
        if (cnt == K) {
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << 0 << std::endl;
    return 0;
}