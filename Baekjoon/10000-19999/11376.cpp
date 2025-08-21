#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
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
    
    cin >> N >> M;

    int s = 0;
    int e = 2001;
    for (int i = 1; i <= N; i++)
        addEdge(s, i, 2);
    for (int i = 1; i <= M; i++)
        addEdge(i + 1000, e, 1);

    for (int i = 1; i <= N; i++) {
        int cnt; cin >> cnt;
        while (cnt--) {
            int work; cin >> work;
            addEdge(i, work + 1000, 1);
        }
    }

    int totalWork = 0;
    while (1) {
        bfs(s, e);
        if (prevNode[e] == -1) break;

        int cur = e;
        while (cur != s) {
            int prev = prevNode[cur];
            flow[prev][cur]++;
            flow[cur][prev]--;
            cur = prev;
        }
        totalWork++;
    }
    cout << totalWork << endl;
    return 0;
}