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
    
    ll N; cin >> N;
    string s; cin >> s;

    int hcnt = 0, ocnt = 0;
    for (auto &i : s) if (i == 'H') hcnt++; else ocnt++;
    if (s.length() % 3 != 0 || ocnt * 2 != hcnt) {
        cout << "mix" << endl;
        return 0;
    }

    hcnt = 0, ocnt = 0;
    bool f = true;
    for (int i = 0; i < s.length(); i++) {
        while (s[i] == 'H') i++, hcnt++;
        while (s[i] == 'O') i++, ocnt++;
        if (hcnt < ocnt) {
            f = false;
            return 0;
        }
        hcnt = ocnt = 0; i--;
    }

    if (f) {
        cout << "pure" << endl;
        return 0;
    }

    f = true;
    hcnt = 0, ocnt = 0;
    reverse(all(s));
    for (int i = 0; i < s.length(); i++) {
        while (s[i] == 'H') i++, hcnt++;
        while (s[i] == 'O') i++, ocnt++;
        if (hcnt < ocnt) {
            f = false;
            return 0;
        }
        hcnt = ocnt = 0; i--;
    }

    cout << (f ? "pure" : "mix") << endl;
    return 0;
}