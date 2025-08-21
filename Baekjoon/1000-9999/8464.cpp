#include <iostream>
#include <algorithm>
#include <vector>
using ll = long long;

ll K;
int mu[1000000] = {0, };

//use mobius function, log n
//also make n log log n like erastothenes sieve
void init() {
    mu[1] = 1;
    for (int i = 1; i <= 1000000; i++) {
        for (int j = 2 * i; j <= 1000000; j += i) {
            mu[j] -= mu[i];
        }
    }
}

ll getSFCnt(ll n) {
    ll cnt = 0;
    for (ll i = 1; i * i <= n; i++) {
        cnt += (mu[i]) * (n / (i * i));
    }
    return cnt;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    init();

    std::cin >> K;

    ll lo = 0;
    ll hi = 1e11; // 시간초과 코드로 범위 크게 잡고 max찾음 : 25505460948
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;

        ll SFCnt = getSFCnt(mid);
        ll nonSFCnt = mid - SFCnt;
        if (nonSFCnt >= K) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    std::cout << hi << std::endl;
    return 0;
}