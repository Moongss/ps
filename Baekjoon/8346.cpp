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
    
    ll ans = 0;
    int k; cin >> k;
    vector<int> v(101010);
    for (int i = 0; i <= k; i++) {
        cin >> v[i];
    }

    ll t = 0;
    while (true) {
        if (v[t] == 0) {
            ans++;
            break;
        }
        else {
            if (v[t] % 2) {
                v[t+1] += v[t] / 2;
            } else {
                v[t+1] += (v[t] - 1) / 2;
                ans += 1LL << t;
            }
            ans += 1LL<< t;
        }
        t++;
    }

    cout << ans << endl;
    return 0;
}