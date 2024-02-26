#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int V, E;
int c[2020][2020];
int f[2020][2020];
int p[2020];
vector<int> adj[2020];

int cost[2020][2020];
int dist[2020];
bool inQ[2020];

void init() {
    memset(c, 0, sizeof(c));
    memset(f, 0, sizeof(f));
    for (auto &x : adj) {
        x.clear();
    }
    memset(cost, 0, sizeof(cost));
}

void addEdge(int u, int v, int cst, int cap) {
    c[u][v] = cap;

    adj[u].push_back(v);
    adj[v].push_back(u);

    cost[u][v] = cst;
    cost[v][u] = -cst;
}

void bfs(int s, int e) {
    memset(p, -1, sizeof(p));
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    memset(inQ, false, sizeof(inQ));

    queue<int> q; q.push(s);
    inQ[s] = true; dist[s] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        inQ[cur] = false;

        for (auto &nxt : adj[cur]) {
            if (c[cur][nxt] - f[cur][nxt] <= 0) continue;
            if (dist[nxt] <= dist[cur] + cost[cur][nxt]) continue;

            dist[nxt] = dist[cur] + cost[cur][nxt];
            p[nxt] = cur;
            if (!inQ[nxt]) {
                inQ[nxt] = true;
                q.push(nxt);
            }
        }
    }
}

int main() {
    fastio;
    
    while (true) {
        cin >> V >> E;
        if (cin.eof()) break;
        init();
        for (int i = 1; i <= V; i++) {
            if (i == 1 || i == V)
                addEdge(i * 2 - 1, i * 2, 0, 2);
            else
                addEdge(i * 2 - 1, i * 2, 0, 1);
        }

        for (int i = 0; i < E; i++) {
            int a, b, c; cin >> a >> b >> c;
            addEdge(a * 2, b * 2 - 1, c, 1);
        }

        int s = 1, e = V * 2;
        int totalCost = 0;
        while (1) {
            bfs(s, e);
            if (p[e] == -1) break;

            int curFlow = 0x3f3f3f3f;
            for (int i = e; i != s; i = p[i]) {
                curFlow = min(curFlow, c[p[i]][i] - f[p[i]][i]);
            }

            for (int i = e; i != s; i = p[i]) {
                totalCost += curFlow * cost[p[i]][i];
                f[p[i]][i] += curFlow;
                f[i][p[i]] -= curFlow;
            }
        }
        cout << totalCost << endl;
    }
    return 0;
}