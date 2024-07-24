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

const ll inf = (1LL << 63) - 1;

ll dp[1010101];
ll sum = 0;

int main() {
    fastio;
    
    dp[1] = 0;
    dp[2] = 1;
    for (ll i = 3; i <= 1000000; i++) {
        if (!(i % 3)) dp[i] = (i / 3) * (i * 2 / 3) + dp[i / 3] + dp[i * 2 / 3];
        else if (!(i % 2)) dp[i] = (i / 2) * (i / 2) + dp[i / 2] * 2;
        else dp[i] = (i - 1) + dp[i - 1];
    }

    int T; cin >> T;
    while (T--) {
        int N; cin >> N; cout << dp[N] << endl;
    }
    return 0;
}