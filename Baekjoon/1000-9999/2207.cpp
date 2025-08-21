#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
vector<int> adj[20001];
int scc[20001];
int sccIdx = 0;
int parent[20001];
int parentIdx = 0;
bool finished[20001];
stack<int> s;

int SCC(int cur) {
    s.push(cur);
    int ret = parent[cur] = ++parentIdx;
    for (auto nxt : adj[cur]) {
        if (!parent[nxt]) ret = min(ret, SCC(nxt));
        else if (!finished[nxt]) ret = min(ret, parent[nxt]);
    }
    if (ret == parent[cur]) {
        while (1) {
            int t = s.top(); s.pop();
            scc[t] = sccIdx;
            finished[t] = true;
            if (t == cur) break;
        }
        ++sccIdx;
    }
    return ret;
}

int main() {
    fastio;
    cin >> N >> M;
    while (N--) {
        int a, b; cin >> a >> b;

        a = (abs(a) - 1) * 2 + (a < 0);
        b = (abs(b) - 1) * 2 + (b < 0);

        adj[a ^ 1].push_back(b);
        adj[b ^ 1].push_back(a);
    }

    for (int i = 0; i < 2 * M; i++) if (!parent[i]) SCC(i);
    for (int i = 0; i < 2 * M; i+=2) {
        if (scc[i] == scc[i + 1]) {
            cout << "OTL" << endl;
            return 0;
        }
    }
    cout << "^_^" << endl;
    return 0;
}