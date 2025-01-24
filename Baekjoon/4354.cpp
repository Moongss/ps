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

int fail[1010101];
string s;

int main() {
    fastio;
    
    while (cin >> s) {
        if (s == ".") break;

        memset(fail, 0, sizeof(fail));
        for (int i = 1, j = 0; i < s.length(); i++) {
            while (j > 0 && s[i] != s[j]) j = fail[j - 1];
            if (s[i] == s[j]) {
                fail[i] = j + 1;
                j++;
            }
        }

        int fmax = fail[s.length() - 1];
        if (fmax % (s.length() - fmax)) cout << 1 << endl;
        else cout << (fmax / (s.length() - fmax)) + 1 << endl;
    }

    return 0;
}