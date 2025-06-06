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

map<string, int> m;
int main() {
    fastio;
    
    string s;
    ll cnt = 0;
    while (cin >> s) {
        m[s]++;
        cnt++;
    }
    if (cnt == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll sum = 0;
    for (auto [k, v]: m) {
        sum += v * v;
    }

    cout << fixed << setprecision(6) <<  1 - sum * 1.0f / (cnt * cnt) << endl;
    return 0;
}