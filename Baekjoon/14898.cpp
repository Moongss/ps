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

int N, Q;
int arr[1010101];
int cvt[1010101];

vector<int> tr[4040404];
unordered_map<int, int> m;

void init(int s, int e, int node) {
    if (s == e) {
        tr[node].push_back(cvt[s]);
        return;
    }

    int mid = s + e >> 1;
    init(s, mid, node << 1);
    init(mid + 1, e, node << 1 | 1);

    tr[node].resize(tr[node << 1].size() + tr[node << 1 | 1].size());
    merge(all(tr[node << 1]), all(tr[node << 1 | 1]), tr[node].begin());
}

int query(int s, int e, int l, int r, int node) {
    if (s > r || e < l) return 0;
    if (l <= s && e <= r) {
        return tr[node].size() - upper(tr[node], r);
    }

    int mid = s + e >> 1;
    return query(s, mid, l, r, node << 1) + query(mid + 1, e, l, r, node << 1 | 1);
}

int main() {
    fastio;

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = N; i >= 1; i--) {
        if (!m[arr[i]]) cvt[i] = N + 1;
        else cvt[i] = m[arr[i]];

        m[arr[i]] = i;
    }

    init(1, N, 1);
    
    cin >> Q;
    int prevQ = 0;
    while (Q--) {
        int x, r; cin >> x  >> r;
        int l = x + prevQ;

        prevQ = query(1, N, l, r, 1);
        cout << prevQ << endl;
    }
    
    return 0;
}