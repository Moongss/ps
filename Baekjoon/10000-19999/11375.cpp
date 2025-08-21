#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
int capacity[2020][2020];
int flow[2020][2020];
int prevNode[2020];
vector<int> adj[2020];

void setCapacity(int s, int e, int flow) {
    capacity[s][e] = flow;

    adj[s].push_back(e);
    adj[e].push_back(s);
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

    int s = 0;
    int e = 2001;
    for (int i = 1; i <= N; i++)
        setCapacity(s, i, 1);
    for (int i = 1; i <= M; i++)
        setCapacity(i + 1000, e, 1);

    for (int i = 1; i <= N; i++) {
        int n; cin >> n;
        while (n--) {
            int dest; cin >> dest; dest += 1000;
            setCapacity(i, dest, 1);
        }
    }

    int totalWork = 0;
    while (true) {
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