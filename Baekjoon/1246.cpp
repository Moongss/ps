#include <iostream>
#include <algorithm>

int N, M;
int egg[1000];
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        std::cin >> egg[i];
    }

    std::sort(egg, egg + M); // 2 7 8 10 11 19 20 -> 7
    int max = -1;
    int minEgg = -1;
    for (int i = 0; i < M; i++) { //M 4 i 0 ~ 3
        int tmp = std::min(M - i, N) * egg[i];
        if (tmp > max) {
            max = std::max(tmp, max);
            minEgg = egg[i];
        }
    }
    std::cout << minEgg << " " << max << std::endl;
    return 0;
}