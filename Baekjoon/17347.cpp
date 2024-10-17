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

crope r;
int main() {
    fastio;
    
    int T; cin >> T;
    int cur = 0, n;
    while (T--) {
        string q; cin >> q; 
        if (q == "Insert") {
            cin >> n; string s = ""; string tmp;
            cin.ignore();
            while (s.length() < n) {
                getline(cin, tmp);
                s += tmp;
            }
            r.insert(cur, s.c_str());
        } else if (q == "Move") {
            cin >> cur;
        } else if (q == "Delete") {
            cin >> n;
            r.erase(cur, n);
        } else if (q == "Get") {
            cin >> n;
            cout << r.substr(cur, n) << endl;
        } else if (q == "Prev") {
            cur--;
        } else if (q == "Next") {
            cur++;
        }
    }
    return 0;
}