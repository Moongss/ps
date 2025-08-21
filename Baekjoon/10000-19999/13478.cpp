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

int f(int a, int b, int c, int d) {
    if (a < c || b < d) return -1;
    int cnt = 0;
    while (a > c) {
        cnt++; a = (a + 1) / 2;
    }
    while (b > d) {
        cnt++; b = (b + 1) / 2;
    }
    return cnt;
}

int main() {
    fastio;
    
    int W, H, w, h; cin >> W >> H >> w >> h;
    ll sum = 0;

    if (W < H) swap(W, H);
    if (w < h) swap(w, h);

    if (W < w || H < h) {
        cout << -1 << endl;
    } else {
        int ret1 = f(W, H, w, h);
        int ret2 = f(W, H, h, w);
        if (ret1 == -1 || ret2 == -1) cout << max(ret1, ret2) << endl;
        else cout << min(ret1, ret2) << endl;
    }
    return 0;
}