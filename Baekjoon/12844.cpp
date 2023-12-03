#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
constexpr int SZ = 1 << 19;

int N, M, K;
ll tree[SZ << 1];
ll lazy[SZ << 1];

void propagate(int s, int e, int node) {
    if (lazy[node] == 0) return;
    
    tree[node] ^= ((e - s + 1) % 2) * lazy[node];
    if (s != e) {
        lazy[node * 2] ^= lazy[node];
        lazy[node * 2 + 1] ^= lazy[node];
    }
    lazy[node] = 0;
}

void update(int s, int e, int l, int r, int node, int value) {
    propagate(s, e, node);
    if (e < l || r < s) return;
    if (l <= s && e <= r) {
        lazy[node] ^= value;
        propagate(s, e, node);
        return;
    }

    int mid = (s + e) / 2;
    update(s, mid, l, r, node * 2, value);
    update(mid + 1, e, l, r, node * 2 + 1, value);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int query(int s, int e, int l, int r, int node) {
    propagate(s, e, node);
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) {
        return tree[node];
    }

    int mid = (s + e) / 2;
    return query(s, mid, l, r, node * 2) ^ query(mid + 1, e, l, r, node * 2 + 1);
}

int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        update(0, N - 1, i, i, 1, x);
    }

    cin >> M;
    while (M--) {
        int q, i, j, k; cin >> q;
        if (q == 1) {
            cin >> i >> j >> k;
            update(0, N - 1, i, j, 1, k);
        }
        else {
            cin >> i >> j;
            cout << query(0, N - 1, i, j, 1) << endl;
        }
    }
    return 0;
}