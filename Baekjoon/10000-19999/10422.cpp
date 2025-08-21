#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll dp[5001];
ll mod = 1000000007;
int main() {
    fastio;
    
    dp[0] = 1;
    dp[2] = 1;
    dp[4] = 2;
    for (int i = 6; i <= 5000; i += 2) {
        for (int j = 2; j <= i; j += 2) {
            dp[i] += (dp[j - 2] % mod) * (dp[i - j] % mod) % mod;;
            dp[i] %= mod;
        }
    }

    int T; cin >> T;
    while (T--) {
        int x; cin >> x; cout << dp[x] << endl;
    }
    return 0;
}