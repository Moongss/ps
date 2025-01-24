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

int N, K;
vector<int> v;

int main() {
    fastio;
    
    cin >> N >> K;
    v.resize(N); for(auto &i : v) cin >> i;

    int s = -42, e = -42;
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if ((K | v[i]) > K) {
            s = e = -42;
            ret = 0;
        } else {
            if (s < 0) s = i;
            if (e < 0) e = i;
            else e = i;

            ret |= v[i];
            if (ret == K) {
                cout << s+1 << " " << e+1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}