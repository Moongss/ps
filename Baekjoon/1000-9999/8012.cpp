#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
int depth[30001];
int parent[30001][16]; //2^15 = 32768
vector<int> adj[30001];

void init(int cur, int prev) {
    parent[cur][0] = prev;
    depth[cur] = depth[prev] + 1;

    for (int i = 1; i < 16; i++) {
        parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
    }
    for (int nxt : adj[cur]) {
        if (nxt == prev) continue;
        init(nxt, cur);
    }
}

int query(int s, int e) {
    int ret = depth[s] + depth[e];
    if (depth[s] < depth[e]) swap(s, e);
    int diff = depth[s] - depth[e];

    for (int i = 0; i < 16; i++) {
        if (diff & (1 << i)) s = parent[s][i];
    }
    if (s != e) {
        for (int i = 15; i >= 0; i--) {
            if (parent[s][i] != parent[e][i]) {
                s = parent[s][i];
                e = parent[e][i];
            }
        }
        s = parent[s][0];
    }
    return ret - 2 * depth[s];
}

int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    init(1, 0);

    int s, e; s = 1;
    int ret = 0;
    cin >> M;
    while (M--) {
        cin >> e;
        ret += query(s, e);
        s = e;
    }
    cout << ret << endl;
    return 0;
}