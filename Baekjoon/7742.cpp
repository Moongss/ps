#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, Q;
vector<pii> adj[100001];
int parent[100001][18]; //2^17 = 131072
int depth[100001];
int dist[100001];

void init(int cur, int prev) {
    parent[cur][0] = prev;
    depth[cur] = depth[prev] + 1;
    for (int i = 1; i < 18; i++) {
        parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
    }
    for (auto [nxt, d] : adj[cur]) {
        if (nxt == prev) continue;
        dist[nxt] = dist[cur] + d;
        init(nxt, cur);
    }
}

int query(int s, int e) {
    int ret = dist[s] + dist[e];
    if (depth[s] < depth[e]) swap(s, e);

    int diff = depth[s] - depth[e];
    for (int i = 0; i < 18; i++) {
        if (diff & (1 << i)) s = parent[s][i];
    }

    if (s != e) {
        for (int i = 17; i >= 0; i--) {
            if (parent[s][i] != parent[e][i]) {
                s = parent[s][i];
                e = parent[e][i];
            }
        }
        s = parent[s][0];
    }
    return ret -= 2 * dist[s];
}

int main() {
    fastio;
    
    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    init(1, 0);
    while (Q--) {
        int x, y; cin >> x >> y;
        cout << query(x, y) << endl;
    }
    return 0;
}