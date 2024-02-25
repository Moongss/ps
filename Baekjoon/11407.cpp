#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
vector<int> adj[202];
int capacity[202][202];
int flow[202][202];
int prevNode[202];

bool inQ[202];
int dist[202];
int cost[202][202];

void setCapacity(int u, int v, int cap) {
    capacity[u][v] = cap;

    adj[u].push_back(v);
    adj[v].push_back(u);
}

void setCost(int u, int v, int cst) {
    cost[u][v] = cst;
    cost[v][u] = -cst;
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
                inQ[nxt] = true;
                q.push(nxt);
            }
        }
    }
}

int main() {
    fastio;
    
    cin >> N >> M;
    int s = 0, e = N + M + 1;
    for (int i = 1; i <= N; i++) {
        int book; cin >> book;
        setCapacity(i + M, e, book);
    }
    for (int i = 1; i <= M; i++) {
        int book; cin >> book;
        setCapacity(s, i, book);
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            int bookCapacity; cin >> bookCapacity;
            setCapacity(i, j + M, bookCapacity);
        }
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            int deliverCost; cin >> deliverCost;
            setCost(i, j + M, deliverCost);
        }
    }

    int totalBook = 0;
    int totalCost = 0;
    while (true) {
        bfs(s, e);
        if (prevNode[e] == -1) break;

        int curFlow = 0x3f3f3f3f;
        for (int i = e; i != s; i = prevNode[i]) {
            curFlow = min(curFlow, capacity[prevNode[i]][i] - flow[prevNode[i]][i]);
        }

        for (int i = e; i != s; i = prevNode[i]) {
            totalCost += curFlow * cost[prevNode[i]][i];
            flow[prevNode[i]][i] += curFlow;
            flow[i][prevNode[i]] -= curFlow;
        }
        totalBook += curFlow;
    }
    cout << totalBook << endl;
    cout << totalCost << endl;
    return 0;
}