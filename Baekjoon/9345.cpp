#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int T, N, K;
pii tree[1 << 19];

pii init(int l, int r, int node) {
    if (l == r) {
        tree[node] = {l, l};
        return tree[node];
    }

    int mid = l + r >> 1;
    pii ln = init(l, mid, node << 1);
    pii rn = init(mid + 1, r, node << 1 | 1);
    return tree[node] = {min(ln.x, rn.x), max(ln.y, rn.y)};
}

int find(int l, int r, int target, int node) {
    if (target < l || r < target) return -1;
    if (l == r && l == target) {
        return tree[node].x;
    }

    int mid = l + r >> 1;
    return max(find(l, mid, target, node << 1), find(mid + 1, r, target, node << 1 | 1));
}

pii update(int l, int r, int target, int newValue, int node) {
    if (target < l || r < target) return tree[node];
    if (l == r && l == target) {
        return tree[node] = {newValue, newValue};
    }

    int mid = l + r >> 1;
    pii ln = update(l, mid, target, newValue, node << 1);
    pii rn = update(mid + 1, r, target, newValue, node << 1 | 1);

    return tree[node] = {min(ln.x, rn.x), max(ln.y, rn.y)};
}

pii query(int l, int r, int s, int e, int node) {
    if (e < l || r < s) return {INT_MAX, INT_MIN};
    if (s <= l && r <= e) {
        return tree[node];
    }

    int mid = l + r >> 1;
    pii ln = query(l, mid, s, e, node << 1);
    pii rn = query(mid + 1, r, s, e, node << 1 | 1);

    return {min(ln.x, rn.x), max(ln.y, rn.y)};
}

int main() {
    fastio;
    
    cin >> T;
    while (T--) {
        cin >> N >> K;
        memset(tree, 0, sizeof(tree));

        init(0, N - 1, 1);
        while (K--) {
            int Q, A, B; cin >> Q >> A >> B;
            if (Q == 0) {
                int a = find(0, N - 1, A, 1);
                int b = find(0, N - 1, B, 1);
                update(0, N - 1, A, b, 1);
                update(0, N - 1, B, a, 1);
            } else {
                pii ret = query(0, N - 1, A, B, 1);
                cout << (ret.x == A && ret.y == B ? "YES" : "NO") << endl;
            }
        }
    }
    return 0;
}