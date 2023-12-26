#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define MOD 1000000007

ll pow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

int main() {
    fastio;
    ll N, K; cin >> N >> K;

    ll e = N * (N - 1) / 2;
    ll v = pow(2, K - 1);
    if (N == 3) cout << 3 << endl;
    else {
        if (K == 0) cout << N << endl;
        if (K == 1) cout << e % MOD << endl;
        if (K >= 2) {
            cout << ((e % MOD) * (v % MOD)) % MOD << endl;
        }
    }
    return 0;
}