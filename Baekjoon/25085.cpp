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

bool check(ll N) {
    string str = to_string(N);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != str[str.length() - 1 - i]) return false;
    }
    return true;
}
int main() {
    fastio;
    
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll N; cin >> N;
        
        int cnt = 0;
        for (ll i = 1; i * i <= N; i++) {
            if (N % i == 0) {
                if (check(i)) cnt++;
                if (i*i!=N && check(N/i)) cnt++;
            }
        }
        cout << "Case #" << t << ": " << cnt << endl;
    }
    return 0;
}