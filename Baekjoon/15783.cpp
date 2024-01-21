#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;

int cnt = 0;
int sccCnt = 0;
int sccInDegree[100001];
int sccId[100001];
int parent[100001];
vector<int> adj[100001];
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
            if (elem == cur) break;
        }
    }
    return ret;
}

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y; x++; y++;
        adj[x].push_back(y);
    }

    for (int i = 1; i <= N; i++) {
        if (!parent[i]) {
            scc(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (auto nxt : adj[i]) {
            if (sccId[i] != sccId[nxt]) {
                sccInDegree[sccId[nxt]]++;
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= sccCnt; i++) {
        if (!sccInDegree[i]) 
            result++;
    }
    cout << result << endl;
    return 0;
}