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

struct node {
    int Min, Max;

    node(int Min = 42424242, int Max = -42424242) : Min(Min), Max(Max) {}
    node operator+ (const node& rhs) {
        return node(min(Min, rhs.Min), max(Max, rhs.Max));
    }
};

node seg[50505 * 4];
int arr[50505];

void init(int s, int e, int node) {
    if (s == e) {
        seg[node] = {arr[s], arr[s]};
        return;
    }

    int m = s + e >> 1;
    init(s, m, node << 1);
    init(m + 1, e, node << 1 | 1);
    seg[node] = seg[node << 1] + seg[node << 1 | 1];
}

node query(int s, int e, int l, int r, int node) {
    if (r < s || e < l) return {42424242, -42424242};
    if (l <= s && e <= r) return seg[node];

    int m = s + e >> 1;
    return query(s, m, l, r, node << 1) + query(m + 1, e, l, r, node << 1 | 1);
}

int main() {
    fastio;
    
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, n, 1);

    while (q--) {
        int l, r; cin >> l >> r; 
        node ret = query(1, n, l, r, 1);
        cout << ret.Max - ret.Min << endl;
    }
    return 0;
}
