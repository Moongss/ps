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

ll arr[102][102];
int N, M;

int main() {
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i <= N; i++) arr[i][0] = 1;
    for (int i = 0; i <= M; i++) arr[0][i] = 1;

    int Q; cin >> Q;
    vector<pair<pii, pii>> v;
    while (Q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if (x1 < x2) swap(x1, x2);
        if (y1 < y2) swap(y1, y2);
        v.push_back({{x1, y1}, {x2, y2}});
    }

    sort(all(v));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i == 0 && j == 0) continue;
            ll a = (i>0 ? arr[i-1][j] : 0);
            ll b = (j>0 ? arr[i][j-1] : 0);
            
            for (auto &x : v) {
                if (x.x.x == i && x.x.y == j) {
                    if (x.y.x == i - 1 && x.y.y == j) a = 0;
                    if (x.y.x == i && x.y.y == j - 1) b = 0;
                }
            }
            arr[i][j] = a + b;
        }
    }
    arr[0][0] = 0;

    ll sum = arr[N][M];
    cout << sum << endl;
    return 0;
}