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

int N;
int arr[101010];

vector<int> tr[404040];

void init(int s, int e, int node) {
    if (s == e) {
        tr[node].push_back(arr[s]);
        return;
    }

    int mid = s + e >> 1;
    init(s, mid, node << 1);
    init(mid+1, e, node << 1 | 1);

    int l = 0, r = 0;
    vector<int> &lv = tr[node << 1];
    vector<int> &rv = tr[node << 1 | 1];

    while (l < lv.size() && r < rv.size()) {
        if (lv[l] < rv[r]) tr[node].push_back(lv[l++]);
        else tr[node].push_back(rv[r++]);
    }

    while (l < lv.size()) tr[node].push_back(lv[l++]);
    while (r < rv.size()) tr[node].push_back(rv[r++]);
}

int query(int l, int r, int s, int e, int k, int node) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tr[node].size() - upper(tr[node], k);

    int mid = s + e >> 1;
    return query(l, r, s, mid, k, node << 1) + query(l, r, mid+1, e, k, node << 1 | 1);
}

int main() {
    fastio;

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    init(1, N, 1);

    ll last = 0;
    int M; cin >> M;
    while (M--) {
        int a, b, c; cin >> a >> b >> c;
        int i = a ^ last, j = b ^ last, k = c ^ last;
        last = query(i, j, 1, N, k, 1);
        cout << last << endl;
    }
    
    return 0;
}