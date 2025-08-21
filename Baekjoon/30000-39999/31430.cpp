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

int main() {
    fastio;
    
    int T; cin >> T;
    ll A, B; string s;
    if (T == 1) {
        cin >> A >> B;

        ll sum = A+B; // 2*10^18
        s = "";
        while (sum) {
            s += 'a' + (sum % 26);
            sum /= 26;
        }
        while (s.size() < 13) s += 'a';
        reverse(all(s));
        cout << s << endl;
    } else {
        cin >> s;

        ll sum = 0;
        for (ll i = 0; i < s.size(); i++) {
            sum *= 26;
            sum += s[i] - 'a';
        }
        cout << sum << endl;
    }
    return 0;
}