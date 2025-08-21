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

int N, C;
vector<ll> v;
vector<ll> l, r;

int main() {
    fastio;
    
    cin >> N >> C;
    v.resize(N); for (auto &i : v) cin >> i;

    
    if (N == 1) {
        cout << (v[0] <= C ? 2 : 1) << endl;
        return 0;
    }
    int mid = N / 2;
    for (int i = 0; i < (1 << mid); i++) {
        ll sum = 0;
        for (int j = 0; j < mid; j++) {
            if (i & (1 << j)) sum += v[j];
        }
        l.push_back(sum);
    }
    for (int i = 0; i < (1 << (N - mid)); i++) {
        ll sum = 0;
        for (int j = 0; j < N - mid; j++) {
            if (i & (1 << j)) sum += v[mid + j];
        }
        r.push_back(sum);
    }

    sort(all(r)); sort(all(l));

    ll result = 0;
    for (auto &x : l) {
        result += upper(r, C - x); 
    }
    cout << result << endl;
    return 0;
}

// 0 2 

// 0 2

// x : 0, C = 1
// C-x : 1

// x : 2, C = -1;
// C-x: -1

// 0 -> 0 1 2 
