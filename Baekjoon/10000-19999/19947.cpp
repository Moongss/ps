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

ll dp[11][3];
int H, Y;
int main() {
    fastio;

    cin >> H >> Y;
    dp[0][0] = dp[0][1] = dp[0][2] = H;
    for (int i = 1; i <= Y; i++) {
        dp[i][0] = (max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) * 105) / 100;
        if (i >= 3) dp[i][1] = max(dp[i - 3][0], max(dp[i - 3][1], dp[i - 3][2])) * 120 / 100;
        if (i >= 5) dp[i][2] = max(dp[i - 5][0], max(dp[i - 5][1], dp[i - 5][2])) * 135 / 100;
    }
    cout << max(dp[Y][0], max(dp[Y][1], dp[Y][2])) << endl;
    return 0;
}