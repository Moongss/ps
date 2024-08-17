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

int dp[1001][2];
int main() {
    fastio;
    
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int ret = 0;
        memset(dp, 0x3f, sizeof(dp));

        int X, Y; string str;
        cin >> X >> Y >> str;

        if (str[0] == 'C') dp[0][0] = 0;
        else if (str[0] == 'J') dp[0][1] = 0;
        else dp[0][0] = dp[0][1] = 0;

        for (int j = 1; j < sz(str); j++) {
            if (str[j] == 'C' || str[j] == '?') dp[j][0] = min(dp[j - 1][0], dp[j - 1][1] + Y);
            if (str[j] == 'J' || str[j] == '?') dp[j][1] = min(dp[j - 1][0] + X, dp[j - 1][1]);
            // cout << "j : " << dp[j][0] << " " << dp[j][1] << endl;
        }
        cout << "Case #" << i << ": " << min(dp[sz(str) - 1][0], dp[sz(str) - 1][1]) << endl;
    }
    return 0;
}