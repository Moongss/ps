#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M, R;
vector<int> adj[100001];
int depth[100001];
int cnt = 1;

void dfs(int cur, int curDepth) {
    depth[cur] = curDepth;
    for (auto nxt : adj[cur]) {
        if (depth[nxt] == -1) 
            dfs(nxt, curDepth + 1);
    }
}

int main() {
    fastio;
    
    cin >> N >> M >> R;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
        depth[i] = -1;
    }

    dfs(R, 0);
    for (int i = 1; i <= N; i++) {
        cout << depth[i] << endl;
    }
    return 0;
}