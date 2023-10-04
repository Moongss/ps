#include <iostream>
using ll = long long;

int N;
ll A[20000], B[20000], C[20000];

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> C[i] >> B[i];
    }

    ll lo = 0;
    ll hi = 2147483648; // 확실히 모든 값이 t/f가 될 수 있으면 left <= right 조건이 좋아보인다.
    ll mid;
    ll result = -1;
    while (lo + 1 < hi) {
        mid = (lo + hi) / 2;

        ll cnt = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] > mid) continue;
            cnt += (std::min(C[i], mid) - A[i]) / B[i] + 1;
        }

        if (cnt % 2 == 0) {
            lo = mid;
        } else {
            hi = mid;
            result = cnt; // tmp
        }
    }

    if (result < 0) {
        std::cout << "NOTHING" << std::endl;
    } else {
        result = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] > hi || C[i] < hi) continue;
            if (hi == A[i] || (hi - A[i]) % B[i] == 0)
                result++;
        }
        std::cout << hi << " " << result << std::endl;
    }
    return 0;
}