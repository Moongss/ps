#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
vector<int> adj[100001];
int parent[100001][18]; //2^17 = 131072
int depth[100001];

void init(int cur, int prev) {
    parent[cur][0] = prev;
    depth[cur] = depth[prev] + 1;
    for (int i = 1; i < 18; i++) {
        parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
    }
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

        int diff = depth[a] - depth[b];
        for (int i = 0; i < 18; i++) {
            if (diff & (1 << i)) a = parent[a][i];
        }

        if (a == b) cout << a << endl;
        else {
            for (int i = 17; i >= 0; i--) {
                if (parent[a][i] != parent[b][i]) {
                    a = parent[a][i];
                    b = parent[b][i];
                }
            }
            cout << parent[a][0] << endl;
        }
    }
    return 0;
}