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

int N, M;
int arr[505050];
ll tr[505050 * 4];

void init(int l, int r, int node) {
    if (l == r) {
        tr[node] = arr[l];
        return;
    }

    int mid = l + r >> 1;
    init(l, mid, node << 1);
    init(mid + 1, r, node << 1 | 1);
    tr[node] = tr[node << 1] + tr[node << 1 | 1];
}

void update(int l, int r, int target, int v, int node) {
    if (target < l || r < target) return;
    if (l == r && l == target) {
        tr[node] += v;
        return;
    }

    int mid = l + r >> 1;
    update(l, mid, target, v, node << 1);
    update(mid + 1, r, target, v, node << 1 | 1);
    tr[node] = tr[node << 1] + tr[node << 1 | 1];
}

ll query(int l, int r, int k, int node) {
    if (l == r) return r;

    int mid = l + r >> 1;
    if (tr[node << 1] >= k) return query(l, mid, k, node << 1);
    else return query(mid + 1, r, k - tr[node << 1], node << 1 | 1);
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    init(1, N, 1);
    cin >> M;
    for (int i = 0; i < M; i++) {
        int q; cin >> q;
        if (q == 1) {
            int x, y; cin >> x >> y;
            update(1, N, x, y, 1);
        } else {
            int x; cin >> x;
            cout << query(1, N, x, 1) << endl;
        }
    }
    return 0;
}