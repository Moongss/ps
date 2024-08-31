#include <bits/stdc++.h>
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
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int main() {
    fastio;

    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int C, D; cin >> C >> D;

        vector<pii> cv, dv;
        for (int j = 0; j < C; j++) {
            int x, y; cin >> x >> y;
            cv.push_back({x, y});
        }
        for (int j = 0; j < D; j++) {
            int x, y; cin >> x >> y;
            dv.push_back({x, y});
        }

        sort(all(cv)); sort(all(dv));
        
    }
    
    return 0;
}