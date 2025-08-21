#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
vector<int> adj[100001];
int parent[100001][18]; //2^17 = 131072
int depth[100001];

void init(int cur, int prev) {
    parent[cur][0] = prev;
    depth[cur] = depth[prev] + 1;
    for (int i = 1; i < 18; i++) {
        parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
    }
    for (int nxt : adj[cur]) {
        if (nxt == prev) continue;
        init(nxt, cur);
    }
}

int query(int l, int r) {
    if (depth[l] < depth[r]) swap(l, r);
    int diff = depth[l] - depth[r];
    for (int i = 0; i < 18; i++) {
        if (diff & (1 << i)) l = parent[l][i];
    }

    if (l != r) {
        for (int i = 17; i >= 0; i--) {
            if (parent[l][i] != parent[r][i]) {
                l = parent[l][i];
                r = parent[r][i];
            }
        }
        l = parent[l][0];
    }
    return l;
}

int main() {
    fastio;

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    init(1, 0);

    cin >> M;
    while (M--) {
        int r, u, v; cin >> r >> u >> v;
        int LCA_uv = query(u, v);
        int LCA_ru = query(r, u);
        int LCA_rv = query(r, v);

        int maxDepth = max(depth[LCA_uv], max(depth[LCA_ru], depth[LCA_rv]));
        if (depth[LCA_uv] == maxDepth) cout << LCA_uv << endl;
        else if (depth[LCA_ru] == maxDepth) cout << LCA_ru << endl;
        else cout << LCA_rv << endl;
    }
    return 0;
}