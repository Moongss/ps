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

int N, K;
int arr[252525];
int tr[252525 * 4];

void update(int l, int r, int target, int value, int node) {
    if (l > target || r < target) return;
    if (l == r) {
        tr[node] += value;
        return;
    }

    int mid = l + r >> 1;
    update(l, mid, target, value, node * 2);
    update(mid + 1, r, target, value, node * 2 + 1);
    tr[node] = tr[node * 2] + tr[node * 2 + 1];
}

int query(int l, int r, int k, int node) {
    if (l == r) return l;

    int mid = l + r >> 1;
    if (tr[node * 2] >= k)
        return query(l, mid, k, node * 2);
    else
        return query(mid + 1, r, k - tr[node * 2], node * 2 + 1);
}

int main() {
    fastio;
    
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    ll sum = 0;
    for (int i = 1; i <= N; i++) {
        update(0, 250000, arr[i], 1, 1);
        if (i < K) continue;
        if (i > K) update(0, 250000, arr[i - K], -1, 1);
        sum += query(0, 250000, (K + 1) / 2, 1);
    }   
    cout << sum << endl;
    return 0;
}