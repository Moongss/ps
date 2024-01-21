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
int sccId[2000];
int parent[2000];
vector<int> adj[2000];
stack<int> tmp;

void init() {
    cnt = 0;
    sccCnt = 0;
    memset(sccId, 0, sizeof(sccId));
    memset(parent, 0, sizeof(sccId));
    for (int i = 0; i < 2000; i++) 
        adj[i].clear();
    while (!tmp.empty()) 
        tmp.pop();
}

bool isClear() {
    for (int i = 0; i < 2 * N; i += 2) {
        if (sccId[i] == sccId[i + 1])
            return false;
    }
    return true;
}

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
    
    while (cin >> N >> M) {
        init();
        for (int i = 0; i < M; i++) {
            int x, y; cin >> x >> y;
            
            x = (abs(x) - 1) * 2 + (x > 0);
            y = (abs(y) - 1) * 2 + (y > 0);

            adj[x ^ 1].push_back(y);
            adj[y ^ 1].push_back(x);
        }
        adj[0].push_back(1);


        for (int i = 0; i < 2 * N; i++) {
            if (!parent[i])
                scc(i);
        }
        cout << (isClear() ? "yes" : "no") << endl;
    }
    
    return 0;
}