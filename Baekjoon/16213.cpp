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

int N, M, Q;
vector<tuple<int, int, int>> adj;
int parent[200001];
vector<int> v;
vector<pii> vv;
pii lr[200001];
vector<int> pbs[500001];
int ans[200001];

int getparent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getparent(parent[x]);
}

void U(int x, int y) {
    int Px = getparent(x);
    int Py = getparent(y);

    if (Px < Py) parent[Px] = Py;
    else parent[Py] = Px;
}

bool F(int x, int y) {
    if (getparent(x) == getparent(y)) return true;
    return false;
}

int main() {
    fastio;

    cin >> N >> M >> Q;
    for (int i = 0; i < M; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj.push_back({w, a, b});
        v.push_back(w);
    }

    compress(v);
    for (int i = 0; i < M; i++) {
        get<0>(adj[i]) = lower(v, get<0>(adj[i]));
    }

    sort(all(adj), [] (auto &a, auto &b) {
        return get<0>(a) < get<0>(b);
    });
    for (int i = 0; i < Q; i++) {
        int x, y; cin >> x >> y;
        vv.push_back({x, y});
        lr[i] = {0, M}; // 0, M-1사이로 정답나옴. l이 정답.
    }

    //pbs
    while (1) {
        for (int i = 0; i <= 500000; i++) pbs[i].clear();
        for (int i = 0; i <= N; i++) parent[i] = i;
        
        bool f = true;
        for (int i = 0; i < Q; i++) {
            if (!(lr[i].x + 1 < lr[i].y)) continue;
            pbs[(lr[i].x + lr[i].y) / 2].push_back(i);
            f = false;
        }
        if (f) break;

        for (int i = M-1; i >= 0; i--) { // 이미 reverse했는데 왜 또? 간선 큰거부터 해야하지않나?
            // union 
            auto [w, x, y] = adj[i];
                U(x, y);

            // cout << "parent=====" << endl;
            // for (int i = 1; i <= N; i++) {  
            //     cout << parent[i] << " ";
            // } cout << endl;

            for (auto &c : pbs[i]) {
                // find
                if (F(vv[c].x, vv[c].y)) {
                    lr[c].x = i; // 속도가 늘어야 함
                } else {
                    lr[c].y = i;
                }

                // cout << "c : " << c << ", lr[x, y] :" << lr[c].x << " "  << lr[c].y << endl;
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << v[lr[i].x] << endl;
    }
    
    return 0;
}