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

const ll INF = 34343434;

struct Node {
    pll Min, Max;

    Node operator + (Node a) {
        Node ret;

        if (Min.x > a.Min.x) ret.Min = a.Min;
        if (Max.x < a.Max.x) ret.Max = a.Max;
        return ret;
    }
};

int N, Q;
int arr[333334];
Node seg[333334 * 4];

void init(int l, int r, int node) {
    if (l == r) {
        seg[node] = {{arr[l], l}, {arr[l], l}};
        return;
    }

    int mid = l + r >> 1;
    init(l, mid, node * 2);
    init(mid + 1, r, node * 2 + 1);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

pll maxQuery(int l, int r, int s, int e, int node) {
    if (e < l || r < s) return {-INF, 0};
    if (s <= l && r <= e) return seg[node].Max;

    int mid = l + r >> 1;
    pll left = maxQuery(l, mid, s, e, node * 2);
    pll right = maxQuery(mid + 1, r, s, e, node * 2 + 1);
    
    return (left.x > right.x ? left : right);
}

pll minQuery(int l, int r, int s, int e, int node) {
    if (e < l || r < s) return {INF, 0};
    if (s <= l && r <= e) return seg[node].Min;

    int mid = l + r >> 1;
    pll left = minQuery(l, mid, s, e, node * 2);
    pll right = minQuery(mid + 1, r, s, e, node * 2 + 1);
    
    return (left.x < right.x ? left : right);
}

void update(int l, int r, int target, int value, int node) {
    if (l == r) {
        seg[node] = {{value, l}, {value, l}};
    } else {
        int mid = l + r >> 1;
        if (target <= mid) update(l, mid, target, value, node * 2);
        else update(mid + 1, r, target, value, node * 2 + 1);
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }
}

int main() {
    fastio;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    init(1, N, 1);
    while (Q--) {
        int q, l, r; cin >> q >> l >> r;
        
        if (q == 1) {
            update(1, N, l, r, 1);
        } else {
            pll maxElem = maxQuery(1, N, l+1, r-1, 1);
            ll minValue = minQuery(1, N, l, maxElem.y-1, 1).x + minQuery(1, N, maxElem.y+1, r, 1).x;
            cout << maxElem.x - minValue << endl;
        }
    }
    return 0;
}