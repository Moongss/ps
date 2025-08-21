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

int N;
vector<pii> v;
vector<int> ret;
vector<int> ret2;
vector<int> ret3;

int main() {
    fastio;
    
    cin >> N; v.resize(N);
    for (auto &i : v) {
        cin >> i.x >> i.y;
    }
    sort(all(v));

    for (auto &[x, y] : v) {
        if (ret.empty()) {
            ret2.push_back(ret.size());
            ret.push_back(y);
        }
        else {
            int idx = lower(ret, y);
            if (idx < ret.size()) {
                ret[idx] = y;
                ret2.push_back(idx);
            }
            else  {
                ret2.push_back(ret.size());
                ret.push_back(y);
            }
        }
    }

    int cur = ret.size() - 1;
    for (int i = N-1; i >= 0; i--) {
        if (cur == ret2[i]) cur--;
        else ret3.push_back(v[i].x);
    }

    cout << ret3.size() << endl;
    sort(all(ret3));
    for (auto &x : ret3) {
        cout << x << endl;
    }
    return 0;
}