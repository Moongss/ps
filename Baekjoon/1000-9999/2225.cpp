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

ll dp[202][202];
ll MOD = 1e9;
int main() {
    fastio;
    
    dp[0][0] = 1;
    for (int i = 1; i <= 200; i++) {
        for (int j = 0; j <= 200; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i-1][k] % MOD; //before: [k][j-1] ;;
                dp[i][j] %= MOD;
            }
        }
    }

    int N, K;
    cin >> N >> K;
    cout << dp[K][N] << endl;
    return 0;
}