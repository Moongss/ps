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

int n,m,s,e;
int dist[5050];
vector<pii> adj[505050];

int main() {
    fastio;
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    cin >> s >> e;

    for (int i = 1; i <= n; i++) dist[i] = 0x3f3f3f3f;
    priority_queue<pii> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, c] = pq.top(); pq.pop();
        d = -d;

        if (dist[c] < d) continue;
        for (auto [nxt, cost]: adj[c]) {
            if (dist[nxt] > d + cost) {
                dist[nxt] = d + cost;
                pq.push({-dist[nxt], nxt});
            }
        }
    }

    cout << dist[e] << endl;
    return 0;
}