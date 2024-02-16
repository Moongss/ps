#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, P;
int flow[801][801];
int capacity[801][801];
int prevNode[801];
vector<int> adj[801];

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
    cin >> N >> P;
    for (int i = 1; i <= N; i++) {
        capacity[i * 2 - 1][i * 2] = 1;
        adj[i * 2 - 1].push_back(i * 2);
        adj[i * 2].push_back(i * 2 - 1);
    }

    for (int i = 0; i < P; i++) {
        int a, b; cin >> a >> b;

        capacity[a * 2][b * 2 - 1] = 1;
        capacity[b * 2][a * 2 - 1] = 1; //bidirectional...

        //out(a) -> in(b)
        adj[a * 2].push_back(b * 2 - 1);
        adj[b * 2 - 1].push_back(a * 2);

        //out(b) -> in(a)
        adj[b * 2].push_back(a * 2 - 1);
        adj[a * 2 - 1].push_back(b * 2);
    }

    int source = 1 * 2;
    int sink = 2 * 2 - 1;
    int pathSum = 0;
    while (1) {
        bfs(source, sink);
        if (prevNode[sink] == -1) break;

        for (int i = sink; i != source; i = prevNode[i]) {
            flow[prevNode[i]][i]++;
            flow[i][prevNode[i]]--;
        }
        pathSum++;
    }
    cout << pathSum << endl;
    return 0;
}