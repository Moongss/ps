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

int N, M, C;
vector<int> tr[404040];
vector<int> adj[100001];
int s[100001], e[100001];
int arr[100001];
int inv[100001];
int cnt = 0;

void dfs(int cur, int prv) {
    s[cur] = ++cnt;
    inv[cnt] = cur;
    for (int nxt : adj[cur]) {
        if (nxt == prv) continue;
        dfs(nxt, cur);
    }
    e[cur] = cnt;
}

void init(int s, int e, int node) {
    if (s == e) {
        tr[node].push_back(arr[inv[s]]);
        return;
    }
    int m = s + e >> 1;
    init(s, m, node << 1);
    init(m+1, e, node << 1 | 1);

    vector<int> &l = tr[node << 1];
    vector<int> &r = tr[node << 1 | 1];

    int i = 0, j = 0;
    while (i < l.size() && j < r.size()) {
        if (l[i] < r[j]) tr[node].push_back(l[i++]);
        else tr[node].push_back(r[j++]);
    }

    while (i < l.size()) tr[node].push_back(l[i++]);
    while (j < r.size()) tr[node].push_back(r[j++]);
}

ll MOD = 1000000007;
ll query(int s, int e, int l, int r, int k, int node) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tr[node].size() - upper(tr[node], k);

    int m = s + e >> 1;
    return (query(s, m, l, r, k, node << 1) + query(m+1, e, l, r, k, node << 1 | 1));
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 2; i <= N; i++) {
        int a; cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    dfs(1, 0);
    init(1, N, 1);

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        cout << query(1, N, s[i], e[i], arr[i], 1) << endl; 
    }
    return 0;
}