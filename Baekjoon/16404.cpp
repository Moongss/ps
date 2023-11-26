#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

constexpr int SZ = 1 << 17;

int N, M;
vector<int> adj[100001];
int in[100001], out[100001];
ll lazy[SZ << 1];

ll query(int s, int e, int node, int target) {
    if (target < s || e < target) return 0;
    if (s == e && s == target) {
        return lazy[node];
    }

    int mid = (s + e) / 2;
    return lazy[node] + query(s, mid, node * 2, target) + 
           query(mid + 1, e, node * 2 + 1, target);
}

void update(int l, int r, int s, int e, int node, int val) {
    if (e < l || r < s) return;
    if (l <= s && e <= r) {
        lazy[node] += val;
        return;
    }

    int mid = (s + e) / 2;
    update(l, r, s, mid, node * 2, val);
    update(l, r, mid + 1, e, node * 2 + 1, val);
}


int cnt = 0;
void dfs(int cur) {
    in[cur] = ++cnt;
    for (auto child: adj[cur])
        dfs(child);
    out[cur] = cnt;
}

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int parent; cin >> parent;
        if (parent != -1) adj[parent].push_back(i);
    }

    dfs(1);
    for (int i = 0; i < M; i++) {
        int q, t, v; cin >> q;
        if (q == 1) {
            cin >> t >> v;
            update(in[t], out[t], 1, SZ, 1, v);
        }
        else {
            cin >> t;
            cout << query(1, SZ, 1, in[t]) << endl;
        }
    }
    return 0;
}