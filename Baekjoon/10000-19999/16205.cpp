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
    
    int n; cin >> n;
    string s; cin >> s;
    string tmp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '_') {
            tmp += (char)toupper(s[i+1]);
            i++;
        } else {
            tmp += s[i];
        }
    }

    string tmp2 = "";
    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i])) {
            if (i != 0) tmp2 += "_";
            tmp2 += (char)tolower(s[i]);
        } else {
            tmp2 += s[i];
        }
    }

    if (n == 1) {
        cout << s << endl;
        for (auto c : s) {
            if (isupper(c)) cout << "_" << (char)tolower(c);
            else cout << c;
        }
        cout << endl;
        cout << (char)toupper(s[0]) << s.substr(1) << endl;
    } else if (n == 2) {
        cout << tmp << endl;
        cout << s << endl;
        cout << (char)toupper(tmp[0]) << tmp.substr(1) << endl;
    } else {
        cout << (char)tolower(s[0]) << s.substr(1) << endl;
        cout << tmp2 << endl;
        cout << s << endl;
    }
    return 0;
}