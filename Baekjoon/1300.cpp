#include <iostream>

using ll = long long;

ll N, K;

ll solve(ll target) {
    ll result = 0;
    for (int i = 1; i <= N; i++) {
        ll lo = 1;
        ll hi = N;
        ll cnt = 0;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (mid * i <= target) {
                cnt = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        result += cnt;
    }
    return result;
}
int main() {
    std::cin >> N >> K;

    ll lo = 1;
    ll hi = 1e+9;
    ll result = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        std::cout << "mid : " << mid << std::endl;
        if (solve(mid) < K) {
            lo = mid + 1;
        } else {
            result = mid;
            hi = mid - 1;
        }
    }
    std::cout << result << std::endl;
    return 0;
}