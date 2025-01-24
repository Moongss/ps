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

int main() {
    fastio;
    
    int N; cin >> N;

    vector<pii> v(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i].x >> v[i].y;
    }

    int ret = -1;
    for (int i = 1; i <= N; i++) {
        bool f = true;
        if (!(v[i].x <= i && i <= v[i].y)) continue;
        for (int j = v[i].x; j <= v[i].y; j++) {
            if (!(v[i].x <= v[j].x && v[j].y <= v[i].y)) {
                f = false;
                break;
            }
        }
        if (f) ret = max(ret, v[i].y - v[i].x + 1);
    }       
    cout << ret << endl;
    return 0;
}