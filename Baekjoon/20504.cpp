#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int T, N, M;

int cnt = 0;
int sccCnt = 0;
int sccId[200001];
int sccIndegree[200001];
int parent[200001];
bool check[200001];

vector<int> adj[200001];
stack<int> tmp;

int scc(int cur) {
    parent[cur] = ++cnt;
    tmp.push(cur);

    int ret = parent[cur];
    for (auto nxt : adj[cur]) {
        if (parent[nxt] == -1) ret = min(ret, scc(nxt));
        if (sccId[nxt] == -1) ret = min(ret, parent[nxt]);
    }

    if (ret == parent[cur]) {
        while (true) {
            int elem = tmp.top(); tmp.pop();
            sccId[elem] = sccCnt;
            if (cur == elem) break;
        }
        sccCnt++;
    }

    return ret;
}

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    memset(sccId, -1, sizeof(sccId));
    memset(parent, -1, sizeof(parent));
    for (int i = 1; i <= N; i++) {
        if (parent[i] == -1)
            scc(i);
    }

    int startCount = 0;
    for (int i = 1; i <= N; i++) {
        for (auto nxt : adj[i]) {
            if (sccId[i] == sccId[nxt]) continue;
            sccIndegree[sccId[nxt]]++;
        }
    }

    for (int i = 0; i < sccCnt; i++) {
        if (!sccIndegree[i])
            startCount++;
    }

    cin >> T;
    int cnt = 0;
    while (T--) {
        int t; cin >> t;
        if (!sccIndegree[sccId[t]] && !check[sccId[t]]) {
            cnt++;
            check[sccId[t]] = true;
        }
    }

    if (cnt == startCount)
        cout << cnt << endl;
    else
        cout << -1 << endl;
    return 0;
}