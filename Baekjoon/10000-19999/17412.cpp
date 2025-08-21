#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, P;
int flow[401][401];
int capacity[401][401];
int prevNode[401];
vector<int> adj[401];

void bfs(int s, int e) {
    memset(prevNode, -1, sizeof(prevNode));
    queue<int> q;
    q.push(s);

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
    
    cin >> N >> P;
    for (int i = 0; i < P; i++) {
        int a, b; cin >> a >> b;
        
        capacity[a][b] = 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int s = 1, e = 2;
    int totalPath = 0;
    while (1) {
        bfs(s, e);
        if (prevNode[e] == -1) break;

        for (int i = e; i != s; i = prevNode[i]) {
            flow[prevNode[i]][i]++;
            flow[i][prevNode[i]]--;
        }
        totalPath++;
    }
    cout << totalPath << endl;
    return 0;
}