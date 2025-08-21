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
    
    ll d; string s; cin >> d; cin >> s;
    ll x, y; cin >> x >> y;

    pll cur = {0, 0};
    for (int i = 0; i < d; i++) {
        cur = {cur.x * 2LL, cur.y * 2LL};
        if (s[i] == '1') {
            cur.y++;
        } else if (s[i] == '2') {
        } else if (s[i] == '3') {
            cur.x++;
        } else {
            cur.x++; cur.y++;
        }
    }
    // cout << "cur.x : " << cur.x << ", cur.y " << cur.y << endl;
    cur.x -= y;
    cur.y += x;

    // cout << "cur.x : " << cur.x << ", cur.y " << cur.y << endl;
    if (cur.x < 0 || cur.x >= pow(2LL, d) || cur.y < 0 || cur.y >= pow(2LL, d)) {
        cout << -1 << endl;
    } else {
        vector<int> v;
        for (int i = 0; i < d; i++) {
            if (cur.x % 2LL && cur.y % 2LL) {
                v.push_back(4); cur.x--, cur.y--;
            } else if (cur.x % 2) {
                v.push_back(3); cur.x--;
            } else if (cur.y % 2) {
                v.push_back(1); cur.y--;
            } else {
                v.push_back(2);
            }
            cur.x /= 2;
            cur.y /= 2;
        }
        reverse(all(v));
        for (auto &x : v) {
            cout << x;
        }
        cout << endl;
    }
    return 0;
}