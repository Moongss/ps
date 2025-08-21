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
int parent[20000];
int sccId[20000];
int sccCnt = 0;
int result[10000];
vector<int> adj[20000];
vector<vector<int> > sccGroup;
stack<int> tmp;

int scc(int cur) {
    parent[cur] = ++cnt;
    tmp.push(cur);

    int ret = parent[cur];
    for (int nxt : adj[cur]) {
        if (!parent[nxt]) ret = min(ret, scc(nxt));
        if (!sccId[nxt]) ret = min(ret, parent[nxt]);
    }

    if (ret == parent[cur]) {
        sccCnt++;
        vector<int> v; v.clear();
        while (true) {
            int elem = tmp.top(); tmp.pop();
            sccId[elem] = sccCnt;
            v.push_back(elem);
            if (elem == cur) break;
        }
        sccGroup.push_back(v);
    }
    return ret;
}

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        
        x = (abs(x) - 1) * 2 + (x > 0);
        y = (abs(y) - 1) * 2 + (y > 0);
        
        adj[x ^ 1].push_back(y);
        adj[y ^ 1].push_back(x);
    }

    for (int i = 0; i < 2 * N; i++) {
        if (!parent[i]) 
            scc(i);
    }

    for (int i = 0; i < 2 * N; i+=2) {
        if (sccId[i] == sccId[i + 1]) {
            cout << 0 << endl;
            return 0;
        }
    }

    memset(result, -1, sizeof(result));
    for (int i = sccGroup.size() - 1; i >= 0; i--) {
        for (auto elem : sccGroup[i]) {
            int nodeNum = (elem / 2);
            if (result[nodeNum] == -1)
                result[nodeNum] = !(elem & 1);
        }
    }

    cout << 1 << endl;
    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}