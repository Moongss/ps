#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

constexpr int SZ = 1 << 20;

int N, M, K;
ll tree[SZ << 1];
ll lazy[SZ << 1];

void propagate(int s, int e, int node) {
    if (lazy[node] == 0) return;
    tree[node] += (e - s + 1) * lazy[node];
    if (s != e) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

ll query(int s, int e, int l, int r, int node) {
    propagate(s, e, node);
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return tree[node];
    int mid = (s + e) / 2;
    return query(s, mid, l, r, node * 2) + query(mid + 1, e, l, r, node * 2 + 1);
}

void update(int s, int e, int l, int r, int node, ll v) {
    propagate(s, e, node);
    if (e < l || r < s) return;
    if (l <= s && e <= r) {
        lazy[node] += v;
        propagate(s, e, node);
        return;
    }

    int mid = (s + e) / 2;
    update(s, mid, l, r, node * 2, v);
    update(mid + 1, e, l, r, node * 2 + 1, v);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    fastio;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        ll x; cin >> x;
        update(1, N, i, i, 1, x);
    }

    for (int i = 0; i < M + K; i++) {
        ll a, b, c, d; cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update(1, N, b, c, 1, d);
        }
        else {
            cin >> b >> c;
            cout << query(1, N, b, c, 1) << endl;
        }
    }
    return 0;
}