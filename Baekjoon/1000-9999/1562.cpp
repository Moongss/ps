#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll MOD = 1000000000;
ll dp[101][11][1 << 10];

ll setting(int N, int digit, int bitset) {
    if (N == 0) return (__builtin_popcount(bitset) == 10) ? 1 : 0;

    ll &ret = dp[N][digit][bitset];
    if (!ret) {
        if (digit < 9) 
            ret += setting(N - 1, digit + 1, bitset | (1 << (digit + 1)));
        if (digit > 0)
            ret += setting(N - 1, digit - 1, bitset | (1 << (digit - 1)));
    }
    return ret % MOD;
}

int main() {
    fastio;
    
    int N; cin >> N;

    ll result = 0;
    for (int i = 1; i <= 9; i++) {
        result += (setting(N - 1, i, 1 << i) % MOD);
    }
    cout << result % MOD << endl;

    return 0;
}