#include <iostream>

using ll = long long;

const ll SZ = 1 << 19;
ll T[800000];

void Set(int x, ll v) {
    x += SZ; T[x] = v;
    while (x /= 2) T[x] = T[x*2] + T[x*2+1];
}

ll Sum(int l, int r) {
    ll res = 0;
    for (l+=SZ, r+=SZ; l <= r; l/=2, r/=2) {
        if (l % 2 == 1) res += T[l++];
        if (r % 2 == 0) res += T[r--];
    }
    return res;
}

ll N;
int num[200000];
int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> num[i];
    }

    ll result = 0;
    for (int i = N - 1; i >= 0; i--) {
        result += Sum(1, num[i]);
        Set(num[i], 1);
    }
    std::cout << result << std::endl;
    return 0;
}