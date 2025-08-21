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

int main() {
    fastio;
    
    int T; cin >> T;
    while (T--) {
        string S; cin >> S;
        rope<char> r = S.c_str();

        string q;
        while (cin >> q, q != "END") {
            if (q == "I") {
                string R; int X; cin >> R >> X;
                r.insert(X, R.c_str());
            } else {
                int X, Y; cin >> X >> Y;
                cout << r.substr(X, Y - X + 1) << endl;
            }

        }
    }
    return 0;
}