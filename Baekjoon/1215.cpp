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

int main() {
    fastio;
    
    ll n, k; cin >> n >> k;
    ll ret = 0;

    if (n > k) ret = (n - k) * k, n = k;

    ll s = 1;
    ret += k * n; // S - k
    while (s <= n) {
        ll num = k / s; // 몫만큼 곱해서 뺴야됨 그게 나머지가됨
        ll e = k / num; // [s, e] -> num = cnt
        if (e > n) e = n;

        ret -= num * (e - s + 1) * (s + e) / 2;
        s = e + 1;
    }

    cout << ret << endl;
    return 0;
}