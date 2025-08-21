#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int SZ = 1 << 17;
int N, M;
int tree[SZ << 1];
int in[100001], out[100001];
vector<int> adj[100001];
int cnt = 0;

void dfs(int cur) {
    in[cur] = ++cnt;
    for (auto nxt : adj[cur]) {
        dfs(nxt);
    }
    out[cur] = cnt;
}

void update(int s, int e, int target, int node, int val) {
    if (target < s || e < target) return;

    tree[node] += val;
    if (s == e && s == target) return;

    int mid = (s + e) / 2;
    update(s, mid, target, node * 2, val);
    update(mid + 1, e, target, node * 2 + 1, val);
}

int sum(int s, int e, int l, int r, int node) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) {
        return tree[node];
    }

    int mid = (s + e) / 2;
    return sum(s, mid, l, r, node * 2) 
         + sum(mid + 1, e, l, r, node * 2 + 1);
}

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int parent; cin >> parent;
        if (parent != -1) adj[parent].push_back(i);
    }

    dfs(1);
    while (M--) {
        int query; cin >> query;
        if (query == 1) {
            int i, w; cin >> i >> w;
            update(1, N, in[i], 1, w);
        } else {
            int i; cin >> i;
            cout << sum(1, N, in[i], out[i], 1) << endl;
        }
    }
    return 0;
}