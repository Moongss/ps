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

void addEdge(int u, int v, int cap) {
    capacity[u][v] = cap;

    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(int s, int e) {
    memset(prevNode, -1, sizeof(prevNode));
    queue<int> q; q.push(s);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (auto nxt : adj[cur]) {
            if (prevNode[nxt] != -1) continue;
            if (capacity[cur][nxt] - flow[cur][nxt] <= 0) continue;

            prevNode[nxt] = cur;
            q.push(nxt);
            if (nxt == e) return;
        }
    }
}

int main() {
    fastio;
    
    cin >> N >> M;
    int s = 0, e = N + M + 1;
    for (int i = 1; i <= N; i++) {
        int book; cin >> book;
        addEdge(i + M, e, book);
    }
    for (int i = 1; i <= M; i++) {
        int book; cin >> book;
        addEdge(s, i, book);
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            int cap; cin >> cap;
            addEdge(i, j + M, cap);
        }
    }

    int totalBook = 0;
    while (true) {
        bfs(s, e);
        if (prevNode[e] == -1) break;

        int curFlow = 0x3f3f3f3f;
        for (int i = e; i != s; i = prevNode[i]) {
            curFlow = min(curFlow, capacity[prevNode[i]][i] - flow[prevNode[i]][i]);
        }

        for (int i = e; i != s; i = prevNode[i]) {
            flow[prevNode[i]][i] += curFlow;
            flow[i][prevNode[i]] -= curFlow;
        }
        totalBook += curFlow;
    }
    cout << totalBook << endl;
    return 0;
}