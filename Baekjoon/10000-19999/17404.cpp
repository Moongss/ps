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
#define sz(v) (int)v.size()

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N;
int C[1000][3];
int dp[1000][3][3];

int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> C[i][0] >> C[i][1] >> C[i][2];
    }

    int ans = 1e9;
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 3; i++) {
            if (i == k) dp[0][i][i] = C[0][i];
            else dp[0][i][i] = 1e9;
        }

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j][0] = min(dp[i - 1][j][1], dp[i - 1][j][2]) + C[i][0];
                dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + C[i][1];
                dp[i][j][2] = min(dp[i - 1][j][0], dp[i - 1][j][1]) + C[i][2];
            }
        }

        for (int i = 0; i < 3; i++) {
            if (i == k) continue;
            for (int j = 0; j < 3; j++) {
                if (j == i || j == k) continue;
                ans = min(ans, dp[N - 1][i][j]);
            }
        }
    }
    return 0;
}