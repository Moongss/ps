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

const ll INF = 424242424242;

struct Node {
    ll Min, Max, Ans;

    Node operator + (Node a) {
        Node ret;

        ret.Min = min(Min, a.Min);
        ret.Max = max(Max, a.Max);
        ret.Ans = max(Ans, max(a.Ans, a.Max - Min));
        return ret;
    }
};

int N, Q;
int arr[101010];
Node seg[101010 * 4];

void init(int l, int r, int node) {
    if (l == r) {
        seg[node] = {arr[l], arr[l], -INF};
        return;
    }

    int mid = l + r >> 1;
    init(l, mid, node * 2);
    init(mid + 1, r, node * 2 + 1);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(int l, int r, int s, int e, int node ){
    if (r < s || e < l) return -INF;
    if (s <= l && r <= e) return seg[node].Ans;

    int mid = l + r >> 1;
    ll left = query(l, mid, s, e, node * 2);
    ll right = query(mid + 1, r, s, e, node * 2 + 1);
    return max(left, right);
}

void update(int l, int r, int target, int value, int node) {
    if (l == r) {
        seg[node] = {value, value, -INF};
    } else {
        int mid = l + r >> 1;
        if (target <= mid) update(l, mid, target, value, node * 2);
        else update(mid + 1, r, target, value, node * 2 + 1);
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }
}

int main() {
    fastio;

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    cin >> Q;
    init(1, N, 1);

    for (int i = 1; i <= 9; i++) {
        cout << "i :" << i << ", Min: " << seg[i].Min << ", Max : " << seg[i].Max << ", Ans : " << seg[i].Ans << endl;
    }
    while (Q--) {
        int q, l, r; cin >> q >> l >> r;
        
        if (q == 1) {
            update(1, N, l, r, 1);
        } else {
            ll t = query(1, N, l, r, 1);
            cout << (t == -INF ? 0 : t) << endl;
        }
    }
    return 0;
}