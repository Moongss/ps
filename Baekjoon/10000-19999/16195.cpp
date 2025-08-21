#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, m; 
ll dp[1010][1010];
ll pre[1010][1010];
ll mod = 1e9 + 9;
int main() {
    fastio;
    
    int T; cin >> T;
    dp[1][1] = 1;
    dp[2][1] = 1; dp[2][2] = 1;
    dp[3][1] = 1; dp[3][2] = 2; dp[3][3] = 1;
    for (int i = 4; i <= 1000; i++) {
        for (int j = 2; j <= i; j++) {
            dp[i][j] = (dp[i-1][j-1]  + dp[i-2][j-1] + dp[i-3][j-1] ) % mod;
        }
    }

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            pre[i][j] = pre[i][j-1] + dp[i][j] % mod;
            pre[i][j] %= mod;
        }
    }
    while (T--) {
        cin >> n >> m;
        cout << pre[n][m] << endl;
    }
    return 0;
}