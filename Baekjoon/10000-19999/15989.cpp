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

ll dp[10101][4];
int main() {
    fastio;
    
    int t; cin >> t;
    
    dp[1][1] = 1;
    dp[2][1] = 1; dp[2][2] = 1;
    dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;

    for (int i = 4; i <= 10000; i++) {
        dp[i][1] = 1;
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }
    while (t--) {
        int n; cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << endl;
    }
    return 0;
}