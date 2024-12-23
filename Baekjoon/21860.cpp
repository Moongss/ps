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

ll N;
vector<ll> v;
vector<ll> arr[32];

ll cnt[32];
bitset<32> bs;
int main() {
    fastio;
    
    cin >> N;
    v.resize(N); for (auto &i : v) cin >> i;
    for (int i = 0; i < 32; i++) {
        for (auto &x : v) {
            arr[i].push_back(x << (1LL << (i + 1) - 1));
        }
        sort(all(arr[i]));
    }

    // 자기꺼 하면 0
    // 같은 bit켜진거/꺼진거 하면 0
    // 다른거만 하면 됨

    // 3 9 6 6 -> 각각 4개
    // 3 9 -> 서로 하는거 1
    // 6 6 -> 서로 하는거 1
    // 2 * 2 -> 다른거 4
    for (ll i = 0; i < 32; i++) {
        for (int j = 0; j < N; j++) {
            cnt[i] += upper(arr[i], (1LL << (i + 1)) - v[j]) - lower(arr[i], (1LL << i) - v[j]);
            cnt[i] += upper(arr[i], (1LL << (i + 2)) - v[j]) - lower(arr[i], (1LL << (i + 1)) + (1LL << i) - v[j]);
        }
        if (cnt[i] % 2) bs[i] = 1;
    }
    cout << bs.to_ullong() << endl;
    return 0;
}