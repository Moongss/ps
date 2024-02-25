#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int T, N, M;
vector<int> adj[2020];
int c[2020][2020];
int f[2020][2020];
int p[2020];

void init() {
    for (auto x : adj) {
        x.clear();
    }
    memset(c, 0, sizeof(c));
    memset(f, 0, sizeof(f));
}

void addEdge(int u, int v, int cap) {
    c[u][v] = cap;

    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(int s, int e) {
    memset(p, -1, sizeof(p));

    queue<int> q; q.push(s);
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (auto nxt : adj[cur]) {
            if (p[nxt] != -1) continue;
            if (c[cur][nxt] - f[cur][nxt] <= 0) continue;

            p[nxt] = cur;
            q.push(nxt);
            if (nxt == e) return;
        }
    }
}

int main() {
    fastio;
    
    cin >> T;
    int s = 2001, e = 2002;
    while (T--) {
        init();
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int u, v; cin >> u >> v; v += N;
            addEdge(u, v, 1);
        }

        for (int i = 0; i < N; i++) {
            addEdge(s, i, 1);
            addEdge(i + N, e, 1);
        }

        int total = 0;
        while (true) {
            bfs(s, e);
            if (p[e] == -1) break;

            for (int i = e; i != s; i = p[i]) {
                f[p[i]][i]++;
                f[i][p[i]]--;
            }
            total++;
        }
        cout << total << endl;
    }
    return 0;
}