#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M, S, T;

int cnt = 0;
int sccCnt = 0;
int sccId[10001];
int parent[10001];
bool visited[10001];
int sccIndegree[10001];
int dp[10001];

vector<int> sccAdj[10001];
vector<int> adj[10001];
vector<vector<int> > sccGroup;
stack<int> tmp;


int scc(int cur) {
    parent[cur] = ++cnt;
    tmp.push(cur);

    int ret = parent[cur];
    for (auto nxt : adj[cur]) {
        if (!parent[nxt]) ret = min(ret, scc(nxt));
        if (sccId[nxt] == -1) ret = min(ret, parent[nxt]); //before: !sccId[nxt], but sccId start 0...
    }

    if (ret == parent[cur]) {
        sccCnt++;
        vector<int> newSCC;
        while (true) {
            int elem = tmp.top(); tmp.pop();
            sccId[elem] = sccCnt - 1; //0-base change
            newSCC.push_back(elem);
            if (elem == cur) break;
        }
        sccGroup.push_back(newSCC);
    }
    return ret;
}

void topology_sort() {
    queue<int> q;

    for (int id = sccCnt - 1; id >= 0; id--) {
        if (!sccIndegree[id])
            q.push(id);
    }

    while (!q.empty()) {
        int elem = q.front(); q.pop();

        for (auto nxt : sccAdj[elem]) {
            sccIndegree[nxt]--;
            if (dp[elem] != -1)
                dp[nxt] = max(dp[nxt], (int)(dp[elem] + sccGroup[nxt].size()));
            if (sccIndegree[nxt] == 0)
                q.push(nxt);
        }
    }
}
int main() {
    fastio;
    
    cin >> N >> M >> S >> T;
    for (int i = 0; i < M; i++) {
        int A, B; cin >> A >> B;
        adj[A].push_back(B);
    }

    memset(sccId, -1, sizeof(sccId));
    for (int i = 1; i <= N; i++) {
        if (!parent[i])
            scc(i);
    }

    for (int i = 1; i <= N; i++) {
        for (auto nxt : adj[i]) {
            if (sccId[i] == sccId[nxt]) continue;
            sccAdj[sccId[i]].push_back(sccId[nxt]);
            sccIndegree[sccId[nxt]]++;
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[sccId[S]] = sccGroup[sccId[S]].size();
    
    topology_sort();
    if (dp[sccId[T]] == -1) 
        cout << 0 << endl;
    else
        cout << dp[sccId[T]] << endl;
    return 0;
}