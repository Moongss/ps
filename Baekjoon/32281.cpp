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

ll pre[202020];
int main() {
    fastio;
    
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        pre[i] = pre[i-1] + i;
    }

    ll sum = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        if (c == '1') cnt++;
        else sum += pre[cnt], cnt = 0;
    }
    sum += pre[cnt];
    cout << sum << endl;
    return 0;
}