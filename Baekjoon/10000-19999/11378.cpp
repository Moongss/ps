#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M, K;
vector<int> adj[2020];
int prevNode[2020];
int capacity[2020][2020];
int flow[2020][2020];

void addEdge(int u, int v, int c) {
    capacity[u][v] = c;

    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(int s, int e) {
    memset(prevNode, -1, sizeof(prevNode));
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : adj[cur]) {
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
    
    cin >> N >> M >> K;

    int s = 0;
    int e = 2001;
    int dummy = 2002;

    addEdge(s, dummy, K);
    for (int i = 1; i <= N; i++) {
        addEdge(s, i, 1);
        addEdge(dummy, i, K);
    }
    for (int i = 1; i <= M; i++) {
        addEdge(i + 1000, e, 1);
    }

    for (int i = 1; i <= N; i++) {
        int cnt; cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int x; cin >> x;
            addEdge(i, x + 1000, 1);
        }
    }

    int totalWork = 0;
    while (1) {
        bfs(s, e);
        if (prevNode[e] == -1) break;

        for (int i = e; i != s; i = prevNode[i]) {
            flow[prevNode[i]][i]++;
            flow[i][prevNode[i]]--;
        }
        totalWork++;
    }
    cout << totalWork << endl;
    return 0;
}