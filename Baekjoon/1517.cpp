#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

const ll SZ = 1 << 20;
int T[2000000];

void Set(ll x, ll v) {
    x += SZ; T[x] = v;
    while (x /= 2) T[x] = T[x*2] + T[x*2+1];
}

ll Sum(ll l, ll r) {
    ll res = 0;
    for (l+=SZ, r+=SZ; l <= r; l/=2, r/=2) {
        if (l % 2 == 1) res += T[l++];
        if (r % 2 == 0) res += T[r--];
    }
    return res;
}

ll N;
int num[500000];
std::vector<int>compress;
int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> num[i];
        compress.push_back(num[i]);
    }

    std::sort(compress.begin(), compress.end());
    compress.erase(std::unique(compress.begin(), compress.end()), compress.end());

    ll result = 0;
    for (int i = 0; i < N; i++) {
        int cur = std::lower_bound(compress.begin(), compress.end(), num[i]) - compress.begin();
        result += Sum(cur + 1, N);
        Set(cur, 1);
    }
    std::cout << result << std::endl;
    return 0;
}