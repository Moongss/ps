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
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ordered_mset s;

int main() {
    fastio;

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> v;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x; s.insert(x);
            if (i % 2 == 0) {
                v.push_back(*s.find_by_order(i / 2));
            }
        }

        cout << v.size() << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
            if ((i+1) % 10 == 0) cout << endl;
        }
        if (v.size() % 10 != 0) cout << endl;
        s.clear(), v.clear();
    }
    
    return 0;
}