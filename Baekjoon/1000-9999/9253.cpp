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

int fail[200000];

int main() {
    fastio;
    
    string a, b, c;
    cin >> a >> b >> c;

    for (int i = 1, j = 0; i < c.length(); i++) {
        while (j && c[i] != c[j]) j = fail[j - 1];
        if (c[i] == c[j]) {
            fail[i] = ++j;
        }
    }

    int ml = 0;
    for (int i = 0, j = 0; i < a.length(); i++) {
        while (j && a[i] != c[j]) j = fail[j - 1];
        if (a[i] == c[j]) {
            ml = max(ml, j + 1);
            if (j == c.length() - 1) {
                j = fail[c.length() - 1];
            } else {
                j++;
            }
        }
    }

    int ml2 = 0;
        for (int i = 0, j = 0; i < b.length(); i++) {
        while (j && b[i] != c[j]) j = fail[j - 1];
        if (b[i] == c[j]) {
            ml2 = max(ml2, j + 1);
            if (j == c.length() - 1) {
                j = fail[c.length() - 1];
            } else {
                j++;
            }
        }
    }

    if (ml == ml2 && ml == c.length()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}