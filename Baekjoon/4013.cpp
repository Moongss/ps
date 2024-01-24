#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M, S, P;
int dp[500001];
int cost[500001];
bool isResturant[500001];
bool isSccResturant[500001];

int cnt = 0;
int sccCnt = 0;
int parent[500001];
int sccId[500001];
int sccCost[500001];

vector<vector<int>> sccGraph;
vector<vector<int>> adj;
stack<int> tmp;

int scc(int cur) {
    parent[cur] = ++cnt;
    tmp.push(cur);

    int ret = parent[cur];
    for (auto nxt : adj[cur]) {
        if (!parent[nxt]) ret = min(ret, scc(nxt));
        if (!sccId[nxt]) ret = min(ret, parent[nxt]);
    }

    if (ret == parent[cur]) {
        sccCnt++;
        while (true) {
            int elem = tmp.top(); tmp.pop();

            sccId[elem] = sccCnt;
            sccCost[sccId[elem]] += cost[elem];
            if (isResturant[elem])
                isSccResturant[sccId[elem]] = true;
            if (elem == cur) 
                break;
        }
    }

    return ret;
}

int bfs(int start) {
    int ret = 0;
    queue<int> q;

    q.push(sccId[start]);
    dp[sccId[start]] = sccCost[sccId[start]];
    while (!q.empty()) {
        int elem = q.front(); q.pop();

        if (isSccResturant[elem])
            ret = max(ret, dp[elem]);

        for (auto nxt : sccGraph[elem]) {
            //not sccId[nxt]...
            if (dp[nxt] < dp[elem] + sccCost[nxt]) { 
                dp[nxt] = dp[elem] + sccCost[nxt];
                q.push(nxt);
            }
        }
    }

    return ret;
}

int main() {
    fastio;
    
    cin >> N >> M;
    sccGraph.resize(N + 1); //RTE: InSufficientMemory
    adj.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
    }

    cin >> S >> P;
    for (int i = 0; i < P; i++) {
        int x; cin >> x;
        isResturant[x] = true;
    }

    for (int i = 1; i <= N; i++) {
        if (!parent[i])
            scc(i);
    }

    for (int i = 1; i <= N; i++) {
        for (auto nxt : adj[i]) {
            if (sccId[i] == sccId[nxt]) continue;
            sccGraph[sccId[i]].push_back(sccId[nxt]);
        }
    }
    
    cout << bfs(S) << endl;
    return 0;
}