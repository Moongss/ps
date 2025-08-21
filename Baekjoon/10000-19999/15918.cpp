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

int n, x, y, k;
int cnt = 0;
bool chk[13];
bool pos[26];
void solve(int cur, int sum) {
    if (sum > n) {
        cnt++;
        return;
    }

    if (chk[cur]) solve(cur+1, sum+1);
    for (int j = 1; j <= 2 * n - cur - 1; j++) {
        if (pos[j] || pos[j+cur+1]) continue;
        pos[j] = pos[j+cur+1] = true;
        solve(cur+1, sum+1);
        pos[j] = pos[j+cur+1] = false;
    }
}   

int main() {
    fastio;
    
    cin >> n >> x >> y; k = y-x-1;
    pos[x] = pos[y] = chk[k] = true;
    
    solve(1, 1);
    cout << cnt << endl;
    return 0;
}