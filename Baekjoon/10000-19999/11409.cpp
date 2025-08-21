#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
vector<int> adj[808];
int capacity[808][808];
int flow[808][808];
int cost[808][808];

int prevNode[808];
int dist[808];
bool inQ[808];

void addEdge(int u, int v, int cap, int cst) {
    capacity[u][v] = cap;
    cost[u][v] = cst;
    cost[v][u] = -cst;

    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(int s, int e) {
    memset(prevNode, -1, sizeof(prevNode));
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    memset(inQ, false, sizeof(inQ));

    queue<int> q; q.push(s);
    dist[s] = 0; inQ[s] = true;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        inQ[cur] = false;

        for (auto nxt : adj[cur]) {
            if (capacity[cur][nxt] - flow[cur][nxt] <= 0) continue;
            if (dist[nxt] <= dist[cur] + cost[cur][nxt]) continue;

            dist[nxt] = dist[cur] + cost[cur][nxt];
            prevNode[nxt] = cur;
            if (!inQ[nxt]) {
                q.push(nxt);
                inQ[nxt] = true;
            }
        }
    }
}

int main() {
    fastio;
    
    cin >> N >> M;
    int s = 0;
    int e = N + M + 1;

    for (int i = 1; i <= N; i++) {
        addEdge(s, i, 1, 0);
    }
    for (int j = 1; j <= M; j++) {
        addEdge(N + j, e, 1, 0);
    }

    for (int i = 1; i <= N; i++) {
        int num; cin >> num;
        for (int j = 0; j < num; j++) {
            int dest, cst; cin >> dest >> cst;
            addEdge(i, N + dest, 1, -cst);
        }
    }

    int totalFlow = 0;
    int totalCost = 0;
    while (1) {
        bfs(s, e);
        if (prevNode[e] == -1) break;

        for (int i = e; i != s; i = prevNode[i]) {
            totalCost += cost[prevNode[i]][i];
            flow[prevNode[i]][i]++;
            flow[i][prevNode[i]]--;
        }
        totalFlow++;
    }

    cout << totalFlow << endl;
    cout << -totalCost << endl;
    return 0;
}