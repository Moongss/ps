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

ll dp[26][26];
bool flag[26][26];

int R, C;
int N;

int main() {
    fastio;
    
    cin >> R >> C; memset(flag, true, sizeof(flag));
    cin >> N;
    for (int i = 0; i < N; i++) {
        int r, c; cin >> r >> c;
        flag[r][c] = false;
    }


    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (!flag[i][j]) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            if (i == 1 && j == 1) dp[i][j] = 1;
        }
    }
    cout << dp[R][C] << endl;
    return 0;
}