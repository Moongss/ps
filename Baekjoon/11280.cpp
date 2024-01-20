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
vector<int> adj[20000];
stack<int> tmp;

int getSCC(int cur) {
    parent[cur] = ++cnt;
    int ret = parent[cur];
    tmp.push(cur);

    for (auto nxt : adj[cur]) {
        if (!parent[nxt]) ret = min(ret, getSCC(nxt));
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
        int x, y; cin >> x >> y;

        //val 1 -> 0: false, 1: true
        //val 2 -> 2: false, 3: true
        //...
        x = (abs(x) - 1) * 2 + (x > 0);
        y = (abs(y) - 1) * 2 + (y > 0);

        adj[x ^ 1].push_back(y);
        adj[y ^ 1].push_back(x);
    }

    for (int i = 0; i < 2 * N; i++) {
        if (!parent[i])
            getSCC(i);
    }

    for (int i = 0; i < 2 * N; i+=2) {
        if (sccId[i] == sccId[i + 1]) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}