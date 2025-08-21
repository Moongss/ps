#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll MOD = 16769023;
const ll inf = (1LL << 63) - 1;

ll mul(int cur) {
    ll res = 1;
    while (cur) {
        int nxt = cur >> 1;
        if (cur & 1) {
            return (2 * mul(nxt) % MOD * mul(nxt) % MOD) % MOD;
        } else {
            return (mul(nxt) % MOD * mul(nxt) % MOD) % MOD;
        }
        cur >>= 1;
    }
    return 1;
}

int main() {
    fastio;
    
    int n; cin >> n;
    cout << mul((n + 1) / 2) << endl;
    return 0;
}