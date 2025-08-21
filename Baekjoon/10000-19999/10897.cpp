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

ll mod = 1e9 + 7;
pll D[101];

int main() {
    fastio;
    
    // D[1] = {1, 1};
    // for (ll i = 2; i <= 100; i++) {
    //     D[i] = {(D[i-1].y + 1), ((D[i-1].y % mod) + ((D[i-1].y - D[i-1].x + 1) % mod * (i % mod) % mod))%mod};
    //     if (D[i].x < 0) D[i].x += mod;
    //     if (D[i].y < 0) D[i].y += mod;
    //     cout << "i :" << i << ", D : "<< D[i].x << " " << D[i].y << endl;
    // }

    ll prev = 1;
    ll sum = 0;
    int Q; cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int q; cin >> q;
        if (i <= 2) {
            sum += q;
        }
        else sum += (q - 1) * i;
        cout << sum << endl;
    }
    return 0;
}