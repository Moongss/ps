#include <iostream>
#include <algorithm>
using ll = long long;

ll N, M;
ll A[100001];
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A, A + N);
    int mode;
    ll i, j, k;
    while (M--) {
        std::cin >> mode;
        if (mode == 1) {
            std::cin >> k;
            std::cout << N - (std::lower_bound(A, A + N, k) - A) << std::endl;
        } else if (mode == 2) {
            std::cin >> k;
            std::cout << N - (std::upper_bound(A, A + N, k) - A) << std::endl;
        } else {
            std::cin >> i >> j;
            std::cout << std::upper_bound(A, A + N, j) - std::lower_bound(A, A + N, i) << std::endl;
        }
    }
    return 0;
}