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

struct dim3 {
    int x, y, z;

    dim3() {}
    dim3(int x, int y, int z) : x(x), y(y), z(z) {}
};

int main() {
    fastio;
    
    int N; cin >> N;
    dim3 Min, Max;

    Min = {1010, 1010, 1010};
    Max = {0, 0, 0};
    for (int i = 0;i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        Max = {max(Max.x, a), max(Max.y, b), max(Max.z, c)};

        int d, e, f; cin >> d >> e >> f;
        Min = {min(Min.x, d), min(Min.y, e), min(Min.z, f)};

    }

    ll ans = max(0, (Min.x - Max.x)) * max(0, (Min.y - Max.y)) * max(0, (Min.z - Max.z));
    cout << ans << endl;
    return 0;
}