#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int V, E;
int parent[10001];
bool finished[10001];
vector<int> adj[10001];
vector<vector<int>> scc;

stack<int> tmp;
int cnt = 0;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

int SCC(int cur) {
    parent[cur] = ++cnt;
    tmp.push(cur);

    int ret = parent[cur];
    for (int nxt : adj[cur]) {
        if (!parent[nxt]) ret = min(ret, SCC(nxt));
        else if (!finished[nxt]) ret = min(ret, parent[nxt]);
    }

    if (ret == parent[cur]) {
        vector<int> newSCC;
        while (1) {
            int t = tmp.top(); tmp.pop();
            newSCC.push_back(t);
            finished[t] = true;
            if (t == cur) break;
        }
        scc.push_back(newSCC);
    }

    return ret;
}

int main() {
    fastio;
    
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= V; i++) {
        if (!parent[i]) SCC(i);
    }

    for (auto& v : scc) {
        sort(v.begin(), v.end());
    }
    sort(scc.begin(), scc.end(), cmp);

    cout << scc.size() << endl;
    for (auto& v : scc) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << -1 << endl;
    }
    return 0;
}