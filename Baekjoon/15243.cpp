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

int dp[30];
int mod = 1e9 + 7;
int main() {
    fastio;
    
    dp[0] = 1, dp[2] = 3;
    for (int i = 4; i <= 30; i += 2) {
        dp[i] = dp[2] * dp[i - 2];
        for (int j = 4; j <= i; j += 2) {
            dp[i] += dp[i - j] * 2; // back
            while (dp[i] < 0) dp[i] += mod;
            dp[i] %= mod;
        }
    }

    int N; cin >> N; cout << dp[N] << endl;
    return 0;
}