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

int T, N;
const int MOD = 1e9+7;

int arr[202020];
int main() {
    fastio;
    
    arr[1] = 1;
    for (int i = 2; i <= 200000; i++) {
        arr[i] = arr[i-1] + 3;
    }

    cin >> T;
    while (T--) {
        cin >> N;
        if (N <= 2) cout << 2 << endl;
        else cout << arr[N-1] + 2 * arr[N-2] << endl;
    }
    return 0;
}