#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, m, q;
int parent[101010], sz[101010];

struct Edge {
    int s, e, w; 
    Edge(int s, int e, int w): s(s), e(e), w(w) {}
    bool operator <(Edge &e) {
        return w < e.w;
    }
};

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a, sz[a] += sz[b];
}

vector<Edge> v;
pii query[101010];
pii pbs[101010];
vector<int> mid[101010];
pii ret[101010];

int main() {
    fastio;
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        v.push_back({x, y, w});
    }
    sort(all(v));

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> query[i].x >> query[i].y;
        pbs[i] = {-1, m};
    }

    while (true) {
        for (int i = 0; i < 101010; i++) mid[i].clear();

        bool f = true;
        for (int i = 0; i < q; i++) {
            if (pbs[i].x + 1 < pbs[i].y) {
                f = false;
                mid[pbs[i].x + pbs[i].y >> 1].push_back(i);
            }
        }
        if (f) break;

        // 여기서 안하니까 break걸고 초기화되서 난리났음
        for (int i = 0; i < 101010; i++) parent[i] = i;
        for (int i = 0; i < 101010; i++) sz[i] = 1;
        for (int i = 0; i < m; i++) {
            merge(v[i].s, v[i].e);

            for (auto e : mid[i]) {
                if (find(query[e].x) == find(query[e].y)) {
                    pbs[e].y = i;
                    ret[e] = {v[i].w, sz[find(v[i].s)]};
                } else {
                    pbs[e].x = i;
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        if (find(query[i].x) != find(query[i].y)) cout << -1 << endl;
        else cout << ret[i].x << " " << ret[i].y << endl;
    }

    return 0;
}