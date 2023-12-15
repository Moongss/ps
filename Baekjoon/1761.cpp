#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
vector<pii> adj[40001];
int parent[40001][16]; //2^16
int dist[40001] = {0, }; //parent to child
int depth[40001];

void init(int cur, int prev) {
    parent[cur][0] = prev;
    depth[cur] = depth[prev] + 1;
    for (int i = 1; i < 16; i++) {
        parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
    }
    for (auto [nxt, d]: adj[cur]) {
        if (nxt == prev) continue;
        dist[nxt] = dist[cur] + d;
        init(nxt, cur);
    }
}
int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b, d; cin >> a >> b >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }

    init(1, 0);
    cin >> M;
    while (M--) {
        int a, b; cin >> a >> b;
        ll ret = dist[a] + dist[b];
        if (depth[a] < depth[b]) swap(a, b);
        
        int diff = depth[a] - depth[b];
        for (int i = 0; i < 16; i++) {
            if (diff & (1 << i)) a = parent[a][i];
        }

        if (a != b) {
            for (int i = 15; i >= 0; i--) {
                if (parent[a][i] != parent[b][i]) {
                    a = parent[a][i];
                    b = parent[b][i];
                }
            }
            a = parent[a][0];
        }
        cout << ret - 2 * dist[a] << endl;
    }
    return 0;
}