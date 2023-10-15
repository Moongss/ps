#include <iostream>
#include <algorithm>
#include <vector>
using ll = long long;

ll K;

int prime[40558] = {0, }; // 45000, tight: 40558 (K = 1e9 -> 1644934081, sqrt(K) = 40558.xx)
std::vector<int> v;

void primeSet() { // n log log n
    for (int i = 2; i <= 40558; i++) {
        prime[i] = i;
    }
    
    for (int i = 2; i <= 40558; i++) {
        if (prime[i] == 0) continue;
        for (int j = i + i; j <= 40558; j += i) {
            prime[j] = 0;
        }
    }
}

ll cnt = 0;
void solve(ll N, ll idx, ll cur, ll num) {
    if (num > 6 || N < cur * v[idx])
        return;

    while (idx < v.size()) {
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
    primeSet();

    std::cin >> K;

    ll lo = 0;
    ll hi = 1644934081 + 1; // K = 1e9, ans = 1644934081

    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        v.clear();
        for (ll i = 2; i * i <= mid; i++) {
            if (prime[i] == 0) continue;
            v.push_back(i * i);
        }

        cnt = 0;
        solve(mid, 0, 1, 1);

        if (mid - cnt >= K) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    std::cout << hi << std::endl;
    return 0;
}