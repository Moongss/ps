#include <bits/stdc++.h>
#include <ext/rope>

#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())
#define sz(v) (int)v.size()
#define NO {cout << "NO" << endl; return;}
#define YES {cout << "YES" << endl; return;}

using namespace std;
using namespace __gnu_cxx;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

rope<char> r;
int main() {
    fastio;
    
    string S; cin >> S; r = S.c_str();
    int Q; cin >> Q;
    while (Q--) {
        int q; cin >> q;
        if (q == 3) {
            int x; cin >> x; cout << r[x] << endl;
        } else {
            int x, y; cin >> x >> y;
            if (q == 1) {
                r = r.substr(x, y - x + 1) + r.substr(0, x) + r.substr(y + 1, sz(r) - y - 1);
            } else {
                r = r.substr(0, x) + r.substr(y + 1, sz(r) - y - 1) + r.substr(x, y - x + 1);
            }
            // cout << r << endl;
        }
    }

    return 0;
}