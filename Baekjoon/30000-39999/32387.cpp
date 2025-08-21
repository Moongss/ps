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

int N, Q;
unordered_map<int, int> m;
set<int> s;

int main() {
    fastio;
    
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) s.insert(i);
    int cnt = 0;

    while (++cnt <= Q) {
        int t, i; cin >> t >> i;
        if (t == 1) {
            auto it = s.lower_bound(i);
            if (it == s.end())
                cout << -1 << endl;
            else {
                m[*it] = cnt;
                cout << *it << endl;
                s.erase(*it);
            }
        } else {
            if (m.find(i) != m.end()) {
                cout << m[i] << endl;
                s.insert(i);
                m.erase(i);
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}