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

int arr[101010];
int root[101010];
bool checked[101010];
struct Node {
    int l, r;
    ll val;
};
vector<Node> tree;
vector<pii> qv;

int init(int l, int r) {
    int node = sz(tree); tree.push_back({0, 0, 0});
    if (l == r) {
        tree[node].val = 0;
        return node;
    }

    int mid = (l + r) >> 1;
    tree[node].l = init(l, mid);
    tree[node].r = init(mid + 1, r);
    tree[node].val = tree[tree[node].l].val + tree[tree[node].r].val;
    return node;
}

void update(int cur, int l, int r, int target) {
    if (target < l || r < target) return;
    if (l == r) {
        tree[cur].val++;
        return;
    }

    int mid = (l + r) >> 1;
    int left = tree[cur].l, right = tree[cur].r;
    if (target <= mid) {
        tree[cur].l = sz(tree);
        tree.push_back({tree[left].l, tree[left].r, tree[left].val});
        update(tree[cur].l,  l, mid, target);
    } else {
        tree[cur].r = sz(tree);
        tree.push_back({tree[right].l, tree[right].r, tree[right].val});
        update(tree[cur].r, mid + 1, r, target);
    }
    tree[cur].val = tree[tree[cur].l].val + tree[tree[cur].r].val;
}

ll sum(int l, int r, int s, int e, int node) { // node : kth root
    if (e < l || r < s) return 0;
    if (s <= l && r <= e) return tree[node].val;

    int mid = (l + r) >> 1;
    return sum(l, mid, s, e, tree[node].l) + sum(mid + 1, r, s, e, tree[node].r);
}

int main() {
    fastio;
    
    int T; cin >> T;
    while (T--) {
        memset(arr, 0, sizeof(arr));
        memset(root, 0, sizeof(root));
        memset(checked, 0, sizeof(checked));
        tree.clear();
        qv.clear();
        int n, m; cin >> n >> m;

        tree = vector<Node>(1);
        root[0] = init(0, 100000);
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y; x++;
            qv.push_back({x, y});
        }

        int queryIdx = 0;
        sort(all(qv));

        for (int i = 1; i <= 100001; i++) {
            root[i] = sz(tree);
            tree.push_back(tree[root[i - 1]]);
            while (queryIdx < qv.size() && qv[queryIdx].x == i) {
                update(root[i], 0, 100000, qv[queryIdx].y);
                queryIdx++;
            }
        }

        ll ret = 0;
        for (int i = 0; i < m; i++) {
            int l, r, b, t; cin >> l >> r >> b >> t; r++;
            ret += sum(0, 100000, b, t, root[r]) - sum(0, 100000, b, t, root[l]);
        }
        cout << ret << endl;
    }
    return 0;
}