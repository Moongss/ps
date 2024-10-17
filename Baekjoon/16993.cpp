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

struct Node {
    ll ans, lmax, rmax, allsum;

    Node operator + (Node a) {
        Node ret;

        ret.lmax = max(this->lmax, this->allsum + a.lmax);
        ret.rmax = max(this->rmax + a.allsum, a.rmax);
        ret.allsum = this->allsum + a.allsum;
        ret.ans = max(this->rmax + a.lmax, max(this->ans, a.ans));
        return ret;
    }
};

int N, M;
int arr[101010];
Node seg[404040];

void init(int l, int r, int node) {
    if (l == r) {
        seg[node] = {arr[l], arr[l], arr[l], arr[l]};
        return;
    }

    int mid = l + r >> 1;
    init(l, mid, node * 2);
    init(mid + 1, r, node * 2 + 1);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

Node query(int l, int r, int s, int e, int node) {
    if (e < l || r < s) return {(ll)-1e10, (ll)-1e10, (ll)-1e10, 0LL};
    if (s <= l && r <= e) return seg[node];

    int mid = l + r >> 1;
    return query(l, mid, s, e, node * 2) + query(mid + 1, r, s, e, node * 2 + 1);
}

int main() {
    fastio;

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    init(1, N, 1);
    cin >> M;
    while (M--) {
        int l, r; cin >> l >> r;
        cout << query(1, N, l, r, 1).ans << endl;
    }
    return 0;
}