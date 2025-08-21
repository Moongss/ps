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

ll N, D;
vector<pll> v;
ll seg[202020];

void init(int l, int r, int node) {
    if (l == r) {seg[node] = v[l].y; return;}

    int mid = l + r >> 1;
    init(l, mid, node * 2);
    init(mid + 1, r, node * 2 + 1);
    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}

ll query(int l, int r, int s, int e, int node) {
    if (r < s || e < l) return -42;
    if (s <= l && r <= e) return seg[node];

    int mid = l + r >> 1;
    return max(query(l, mid, s, e, node * 2), query(mid + 1, r, s, e, node * 2 + 1));
}

int main() {
    fastio;
    
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    v.push_back({-42, 0});
    sort(all(v));

    init(1, N, 1); 
    int lo = 0, hi = 1;
    int ret = 0;
    for (int i = 1; i <= N; i++) {
        
        while (lo < i && (v[i].x - v[lo].x) > D) lo++;
        while (hi < N && (v[hi].x - v[i].x) <= D) hi++;
        if (v[hi].x - v[i].x > D) hi--;

        ll left = query(1, N, lo, i, 1);
        ll right = query(1, N, i, hi, 1);
        
        // cout << "lo : " << lo <<", hi : " << hi << ", left/right : " << left << "/"<<right << endl;
        if (left >= v[i].y * 2 && right >= v[i].y * 2) ret++;
    }
    cout << ret << endl;
    return 0;
}