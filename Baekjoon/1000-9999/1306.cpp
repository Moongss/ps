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

int M, N;
vector<int> v;
int tr[1010101 * 4];

void update(int l, int r, int target, int value, int node) {
    if (target < l || r < target) return;
    if (l == r) {
        tr[node] = value;
        return;
    }
    int mid = l + r >> 1;
    update(l, mid, target, value, node << 1);
    update(mid + 1, r, target, value, node << 1 | 1);
    tr[node] = max(tr[node << 1], tr[node << 1 | 1]);
}

int main() {
    fastio;
    
    cin >> N >> M;
    v.resize(N + 1); 
    for (int i = 1; i <= N; i++) cin >> v[i];

    for (int i = 1; i < 2 * M - 1; i++) {
        update(1, 1000000, i, v[i], 1);
    }
    for (int i = 2 * M - 1; i <= N; i++) {
        update(1, 1000000, i, v[i], 1);
        cout << tr[1] << " ";
        update(1, 1000000, i - (2 * M - 2), 0, 1);
    }
    return 0;
}