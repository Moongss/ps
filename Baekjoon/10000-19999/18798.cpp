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

struct node {
    ll val;
    ll Kcnt;

    node operator+(const node& t) const {
        return {val & t.val, Kcnt + t.Kcnt};
    }
};

int N, M;
vector<ll> v;
node sg[1 << 20];
ll K;

void init(int s, int e, int node) {
    if (s == e) {
        sg[node].val = v[s];
        sg[node].Kcnt = (v[s] == K);
        return;
    }

    int mid = s + e >> 1;
    init(s, mid, node * 2);
    init(mid + 1, e, node * 2 + 1);
    sg[node] = sg[node * 2] + sg[node * 2 + 1];
}

void update(int s, int e, int l, int r, ll target, int node) {
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        if ((sg[node].val & target) == target) return;
        sg[node].val |= target;
    }
    if (s == e) {
        sg[node].Kcnt = (sg[node].val == K);
        return;
    }

    int mid = s + e >> 1;
    update(s, mid, l, r, target, node * 2);
    update(mid + 1, e, l, r, target, node * 2 + 1);
    sg[node] = sg[node * 2] + sg[node * 2 + 1];
}

ll query(int s, int e, int l, int r, int node) { //GTN
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return sg[node].Kcnt;

    int mid = s + e >> 1;
    return query(s, mid, l, r, node * 2) 
         + query(mid + 1, e, l, r, node * 2 + 1);
}

int main() {
    fastio;
    
    cin >> N >> K;
    v.resize(N + 1); for (int i = 1; i <= N; i++) cin >> v[i];
    init(1, N, 1);

    cin >> M;
    while (M--) {
        ll q, a, b, c; 
        cin >> q;
        if (q == 1) {
            cin >> a >> b >> c;
            update(1, N, a, b, c, 1);
        } else {
            cin >> a >> b;
            cout << query(1, N, a, b, 1) << endl;
        }
    }

    return 0;
}