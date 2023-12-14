#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
vector<int> adj[50001];
int parent[50001];
int depth[50001];

void init(int cur, int prev) {
    parent[cur] = prev;
    depth[cur] = depth[prev] + 1;
    for (int nxt : adj[cur]) {
        if (nxt == prev) continue;
        init(nxt, cur);
    }
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
    cin >> M;
    while (M--) {
        int a, b; cin >> a >> b;
        if (depth[a] < depth[b]) swap(a, b);
        while (depth[a] != depth[b]) a = parent[a];
        while (a != b) {
            a = parent[a];
            b = parent[b];
        }
        cout << a << endl;
    }
    return 0;
}