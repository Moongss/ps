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

int t;
bool f[10] = {0};
bool check(string s) {
    for (char c : s) {
        if (!f[c-'0']) return false;
    }
    return true;
}

bool check2(int n) {
    for (int i = 2; i <= 9 && n > 1; i++) {
        while (n % i == 0) {
            if (!f[i]) return false;
            n /= i;
        }
    }
    return (n <= 9 && f[n]);
}

ll solve(int n) {
    if (n >= 0 && n <= 9) {
        if (f[n]) return 1;
    }

    ll ret = 42424242;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            // cout << "i: " << i << " n/i: " << n/i << endl;
            if (check(to_string(i)) && check(to_string(n/i))) {
                ret = min(ret, (ll)to_string(i).length() + (ll)to_string(n/i).length() + 1);
            }
            else {
                if (check(to_string(i))) {
                    ret = min(ret, solve(n/i) + (int)to_string(i).length() + 1);
                }
                else if (check(to_string(n/i))) {
                    ret = min(ret, solve(i) + (int)to_string(n/i).length() + 1);
                } else {
                    ret = min(ret, solve(i) + solve(n/i) + 1);
                }
            }
        }
    }
    return ret;
}

int main() {
    fastio;
    
    cin >> t;
    for (int l = 1; l <= t; l++) {
        for (int i = 0; i < 10; i++) {
            int x; cin >> x; f[i] = x;
        } 
        int cnt = 0;
        int n; cin >> n; 
        if (check(to_string(n))) {
            cnt = to_string(n).length() + 1;
            cout << "Case #" << l << ": " << cnt << endl;
        } else {
            int ret = solve(n);
            if (ret == 42424242) {
                cout << "Case #" << l << ": " << "Impossible" << endl;
            } else {
                cout << "Case #" << l << ": " << ret + 1<< endl;
            }
        }
    }
    return 0;
}