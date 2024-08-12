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

const ll mod = 1234567;
const ll inf = (1LL << 63) - 1;

int T;
int dp[10][1001];
int main() {
    fastio;
    
    for (int i = 0; i < 10; i++) dp[i][1] = 1;
    for (int i = 2; i <= 1000; i++) {
        dp[1][i] = dp[2][i - 1] + dp[4][i - 1];
        dp[2][i] = dp[1][i - 1] + dp[3][i - 1] + dp[5][i - 1];
        dp[3][i] = dp[2][i - 1] + dp[6][i - 1];
        dp[4][i] = dp[1][i - 1] + dp[5][i - 1] + dp[7][i - 1];
        dp[5][i] = dp[2][i - 1] + dp[4][i - 1] + dp[6][i - 1] + dp[8][i - 1];
        dp[6][i] = dp[3][i - 1] + dp[5][i - 1] + dp[9][i - 1];
        dp[7][i] = dp[4][i - 1] + dp[8][i - 1] + dp[0][i - 1];
        dp[8][i] = dp[7][i - 1] + dp[9][i - 1] + dp[5][i - 1];
        dp[9][i] = dp[8][i - 1] + dp[6][i - 1];
        dp[0][i] = dp[7][i - 1];

        for (int j = 0; j < 10; j++) dp[j][i] %= mod;
    }

    cin >> T;   
    while (T--) {
        int t; cin >> t;
        ll sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += dp[i][t] % mod;
        }
        cout << sum % mod << endl;
    }
    return 0;
}