#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
int capacity[404][404];
int flow[404][404];
int prevNode[404];
vector<int> adj[404];

void bfs(int s, int e) {
    memset(prevNode, -1, sizeof(prevNode));
    queue<int> q; q.push(s);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {
            if (prevNode[nxt] != -1) continue;
            if (capacity[cur][nxt] - flow[cur][nxt] <= 0) continue;

            q.push(nxt);
            prevNode[nxt] = cur;
            if (nxt == e) return;
        }
    }
}

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int S; cin >> S;
        for (int j = 0; j < S; j++) {
            int s; cin >> s;
            capacity[i][s + N] = 1;
            adj[i].push_back(s + N);
            adj[s + N].push_back(i);
        }
    }

    int s = 0;
    int e = 1 + N + M;
    for (int i = 1; i <= N; i++) {
        capacity[s][i] = 1;
        adj[s].push_back(i);
        adj[i].push_back(s);
    }
    for (int i = 1; i <= M; i++) {
        capacity[i + N][e] = 1;
        adj[i + N].push_back(e);
        adj[e].push_back(i + N);
    }
    
    int totalCow = 0;
    while (true) {
        bfs(s, e);
        if (prevNode[e] == -1) break;

        int curCow = 42424242;
        for (int i = e; i != s; i = prevNode[i]) {
            curCow = min(curCow, capacity[prevNode[i]][i] - flow[prevNode[i]][i]);
        }

        for (int i = e; i != s; i = prevNode[i]) {
            flow[prevNode[i]][i] += curCow;
            flow[i][prevNode[i]] -= curCow;
        }
        totalCow += curCow;
    }
    cout << totalCow << endl;
    return 0;
}