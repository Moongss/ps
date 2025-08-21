#include <iostream>
using ld = long double;

int N, L;
int X[100000];
int W[100000];

int main() {
    std::cin >> N >> L;
    for (int i = 0; i < N; i++) {
        std::cin >> X[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> W[i];
    }

    ld lo = 0, hi = L;
    while (lo + 1e-6 < hi) {
        ld mid = (lo + hi) / 2;
        ld sum = 0;
        for (int i = 0; i < N; i++) {
            if (X[i] < mid) {
                sum += W[i] * (mid - X[i]);
            } else {
                sum -= W[i] * (X[i] - mid);
            }
        }

        if (sum >= 0) { // Left > Right -> mid가 왼쪽으로 가야함.
            hi = mid;
        } else { // Left <= Right
            lo = mid;
        }
    }
    printf("%.6Lf\n", hi);
    return 0;
}