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

int t[20], p[20], dp[20];

int main() {
    fastio;
    
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t[i] >> p[i];
        if (i>0) dp[i] = max(dp[i], dp[i-1]);
        for (int j = 0; j <= N; j++) cout << dp[j] << " "; cout << endl;
        if (i+t[i] <= N) {
            dp[i+t[i]] = max(dp[i+t[i]], dp[i] + p[i]);
        }
    }

    int ret = 0;
    for (int i = 1; i <= N; i++) {
        cout << dp[i] << endl;
        ret = max(ret, dp[i]);
    }
    cout << ret << endl;
    return 0;
}