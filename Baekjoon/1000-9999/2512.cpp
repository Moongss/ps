#include <iostream>
#include <algorithm>

int N, M;
int budget[10000];

int main() {
    std::cin >> N;

    int lo = 0;
    int hi = -1;
    for (int i = 0; i < N; i++) {
        std::cin >> budget[i];
        hi = std::max(hi, budget[i] + 1);
    }

    std::cin >> M;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += std::min(mid, budget[i]);
        }

        if (sum <= M)
            lo = mid;
        else
            hi = mid;
    }

    std::cout << lo << std::endl;
    return 0;
}