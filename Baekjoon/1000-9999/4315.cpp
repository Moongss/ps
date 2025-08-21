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

int gu[10101];
bool visited[10101];
vector<int> adj[10101];

pii solve(int cur) {
    if (!adj[cur].size()) return {gu[cur], abs(gu[cur])};

    pii ret = {gu[cur], 0};
    visited[cur] = true;
    for (auto &x : adj[cur]) {
        if (visited[x]) continue;
        pii t = solve(x);
        ret = {ret.x + t.x, ret.y + t.y};
    }
    ret = {ret.x, ret.y + abs(ret.x)};
    return ret;
}

int main() {
    fastio;
    
    while (true) {
        memset(gu, 0, sizeof(gu));
        memset(visited, 0, sizeof(visited));
        for (auto &x : adj) {
            x.clear();
        }
        int n; cin >> n;
        if (n == 0) break;
        
        for (int i = 0; i < n; i++) {
            int node; cin >> node;
            cin >> gu[node]; gu[node]--;
            int m; cin >> m;
            for (int i = 0; i < m; i++) {
                int x; cin >> x;
                adj[node].push_back(x);
                adj[x].push_back(node);
            }
        }
        cout << solve(1).y << endl;
    }
    return 0;
}