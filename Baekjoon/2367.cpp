#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, K, D;
int plate[101];
int prevNode[3030];
int flow[3030][3030];
int capacity[3030][3030];
vector<int> adj[3030];

void setFlow(int s, int e, int flow) {
    capacity[s][e] = flow;

    adj[s].push_back(e);
    adj[e].push_back(s);
}

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
    // fastio;
    
    cin >> N >> K >> D;
    for (int i = 1; i <= D; i++) {
        cin >> plate[i];
    }
    
    int s = 0;
    int e = 333;
    for (int i = 1; i <= N; i++) {
        setFlow(s, i, K);
    }
    for (int i = 1; i <= D; i++) {
        setFlow(N + i, e, plate[i]);
    }
    for (int i = 1; i <= N; i++) {
        int foodCnt; cin >> foodCnt;
        for (int j = 1; j <= foodCnt; j++) {
            int z; cin >> z;
            setFlow(i, N + z, 1);
        }
    }

    int maxPlate = 0;
    while (1) {
        bfs(s, e);
        if (prevNode[e] == -1) break;

        for (int i = e; i != s; i = prevNode[i]) {
            flow[prevNode[i]][i]++;
            flow[i][prevNode[i]]--;
        }
        maxPlate++;
    }
    cout << maxPlate << endl;
    return 0;
}