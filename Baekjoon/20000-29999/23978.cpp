#include <iostream>
#include <vector>

using ll = long long;

ll N, K;
std::vector<ll> A;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> N >> K;
    for (int i = 0; i < N; i++) {
        ll tmp; std::cin >> tmp;
        A.push_back(tmp);
    }

    ll lo = 0;
    ll hi = 1e+10;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        ll midSum = mid * (mid + 1) / 2;
        ll target = K;
        for (int i = 1; i < N; i++) {
            ll tmp = A[i] - A[i - 1];
            ll dist = mid - tmp;
            ll distSum = dist * (dist + 1) / 2;
            if (dist <= 0) {
                target -= midSum;
            } else {
                target -= (midSum - distSum);
            }
            if (target <= 0)
                break;
        }
        if (target > 0)
            target -= midSum;

        if (target <= 0) { // K보다 크거나 같다.
            hi = mid;
        } else {
            lo = mid;
        }
    }
    std::cout << hi << std::endl;
    return 0;
}