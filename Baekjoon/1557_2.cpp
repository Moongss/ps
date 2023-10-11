#include <iostream>
#include <algorithm>
#include <vector>
using ll = long long;

ll K;
int mu[45000] = {0, };

//use mobius function, log n
//also make n log log n like erastothenes sieve
void init() {
    mu[1] = 1;
    for (int i = 1; i <= 45000; i++) {
        for (int j = 2 * i; j <= 45000; j += i) {
            mu[j] -= mu[i];
        }
    }
}

ll getSFCnt(ll n) {
    ll cnt = 0;
    for (ll i = 1; i * i <= n; i++) {
        // std::cout << "i : " << i << "(mu[i]) * (n / (i * i) : " << (mu[i]) * (n / (i * i)) << std::endl;
        cnt += (mu[i]) * (n / (i * i));
    }
    return cnt;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    init();

    std::cin >> K;

    ll lo = 0;
    ll hi = 2e9; // 대충 1e12부터 테스트해서 max찾음 : 25502363010
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;

        if (getSFCnt(mid) >= K) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    std::cout << hi << std::endl;
    return 0;
}