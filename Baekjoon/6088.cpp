#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


int N;
int capacity[52][52];
int flow[52][52];
int prevNode[52];
vector<int> adj[52];

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        char a, b; int c; cin >> a >> b >> c;

        int s = (a > 'Z' ? a - 'a' + 26 : a - 'A');
        int e = (b > 'Z' ? b - 'a' + 26 : b - 'A');

        capacity[s][e] = capacity[e][s] += c;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
}

void bfs(int s, int e) {
    memset(prevNode, -1, sizeof(prevNode));
    queue<int> q; q.push(s);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto next : adj[cur]) {
            if (prevNode[next] != -1) continue;
            if (capacity[cur][next] - flow[cur][next] <= 0) continue;

            //not visited & possible to flow
            q.push(next);
            prevNode[next] = cur;
            if (next == e) return;
        }
    }
}

void edmondsKarp(int s, int e) {
    int totalFlow = 0;
    while (1) {
        bfs(s, e);
        if (prevNode[e] == -1) break;

        int curFlow = 42424242;
        for (int i = e; i != s; i = prevNode[i]) {
            curFlow = min(curFlow, capacity[prevNode[i]][i] - flow[prevNode[i]][i]);
        }

        for (int i = e; i != s; i = prevNode[i]) {
            flow[prevNode[i]][i] += curFlow;
            flow[i][prevNode[i]] -= curFlow;
        }
        totalFlow += curFlow;
    }
    cout << totalFlow << endl;
}

int main() {
    fastio;
    
    init();
    edmondsKarp(0, 25); // A: 0, Z: 25

    return 0;
}