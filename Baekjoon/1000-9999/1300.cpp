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

    ll lo = 0; // 1
    ll hi = 1e+10;
    ll result = 0;
    while (lo + 1 < hi) { // lo <= hi
        ll mid = (lo + hi) / 2;
        if (solve(mid) < K) {
            lo = mid;
        } else { // result variable setting. (if condition is lo <= hi)
            hi = mid;
        }
    }
    std::cout << hi << std::endl;
    return 0;
}