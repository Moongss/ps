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
#define sz(v) (int)v.size()

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int N, M;
ll sx, sy, ex, ey;
vector<ll> v;
int main() {
    fastio;
    
    cin >> N;
    cin >> sx >> sy >> ex >> ey;
    
    v.resize(N + 1);

    ll Min = LLONG_MAX;
    int idx = 0;
    for (int i = 1; i <= N; i++) {
        cin >> M;

        pll prev;
        for (int j = 0; j < M; j++) {
            ll x, y; cin >> x >> y;
            if (j == 0) v[i] += abs(x-sx) + abs(y-sy);
            if (j == M - 1) v[i] += abs(x-ex) + abs(y-ey);
            
            if (j > 0) v[i] += abs(x - prev.x) + abs(y - prev.y);
            prev = {x, y};
        }

        if (v[i] < Min) {
            Min = v[i];
            idx = i;
        }
    }
    cout << idx << endl;
    return 0;
}