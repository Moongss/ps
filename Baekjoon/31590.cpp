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

int N, M; string str;
crope r;

int main() {
    fastio;
    
    cin >> N >> M;
    cin >> str; r = str.c_str();
    r.insert(0, ' ');

    for (int i = 0; i < M; i++) {
        int q; cin >> q;
        if (q == 1) {
            char c; int a; cin >> c >> a;
            r.insert(a, c);
        }
        else {
            int a, b; cin >> a >> b;
            cout << r.substr(a, b - a + 1) << endl;
            r.erase(a, b - a + 1);
        }
    }
    return 0;
}