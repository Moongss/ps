#include <iostream>
#include <algorithm>
#include <vector>
using ll = long long;

ll K;

int prime[1200000] = {0, };
std::vector<int> v;

void primeSet() { // n log log n
    for (int i = 2; i <= 1200000; i++) {
        prime[i] = i;
    }
    
    for (int i = 2; i <= 1200000; i++) {
        if (prime[i] == 0) continue;
        for (int j = i + i; j <= 1200000; j += i) {
            prime[j] = 0;
        }
    }
}

ll cnt = 0;
// ll sum = 0;
void solve(ll N, ll idx, ll cur, ll num) {
    if (num > 6 || N < cur * v[idx]) // 2 3 5 7 11 13. 17부터는 max넘어감.
        return;

    while (idx < v.size()) {
        // sum++;
        if (N < cur * v[idx])
            break;
        if (num % 2 == 1) {
            cnt += N / (cur * v[idx]);
        } else {
            cnt -= N / (cur * v[idx]);
        }
        idx++;
        solve(N, idx, cur * v[idx - 1], num + 1);
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    primeSet();


    // ll sum = 0;
    // ll tmp = 25502363010;
    // for (int i = 2; i <= 1000000; i++) {
    //     if (prime[i] == 0) continue;
    //     std::cout << "tmp / (i * i) : " << tmp / (i * i) << std::endl;
    //     sum += tmp / (i * i);
    //     std::cout << "sum : " << sum << std::endl;
    // }

    std::cin >> K;

    ll lo = 0;
    ll hi = 1e11; // 대충 1e12부터 테스트해서 max찾음 : 25502363010

    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;

        v.clear();
        for (ll i = 2; i * i <= mid; i++) {
            if (prime[i] == 0) continue;
            v.push_back(i * i);
        }

        cnt = 0;
        // sum = 0;
        solve(mid, 0, 1, 1);

        std::cout << "mid : " << mid << ", cnt : " << cnt << std::endl;
        // std::cout << sum << std::endl;
        if (cnt >= K) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    std::cout << hi << std::endl;
    return 0;
}