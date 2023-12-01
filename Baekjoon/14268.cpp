#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

constexpr int SZ = 1 << 17;
int N, M;
int lazy[SZ << 1];
vector<int> adj[SZ];

int in[100001], out[100001];
int cnt = 0;

void update(int s, int e, int l, int r, int node, int value) {
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        lazy[node] += value;
        return;
    }

    int mid = (s + e) / 2;
    update(s, mid, l, r, node * 2, value);
    update(mid + 1, e, l, r, node * 2 + 1, value);
}

int query(int s, int e, int target, int node) {
    if (target < s || e < target) return 0;
    if (s == e && target == s) return lazy[node];

    int mid = (s + e) / 2;
    return lazy[node] + query(s, mid, target, node * 2)
                      + query(mid + 1, e, target, node * 2 + 1);
}

void dfs(int cur) {
    in[cur] = ++cnt;
    for (int nxt : adj[cur]) {
        dfs(nxt);
    }
    out[cur] = cnt;
}

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int p; cin >> p;
        if (p == -1) continue;
        adj[p].push_back(i);
    }

    dfs(1);
    while (M--) {
        int q, i, w; cin >> q;
        if (q == 1) {
            cin >> i >> w;
            update(1, N, in[i], out[i], 1, w);
        } else {
            cin >> i;
            cout << query(1, N, in[i], 1) << endl;
        }
    }
    return 0;
}