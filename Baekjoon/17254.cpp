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
    
    int n, m; cin >> n >> m;
    vector<pair<pii, char>> v;
    
    for (int i = 0; i < m; i++) {
        int a, b; char c; cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }

    sort(all(v), [&](pair<pii, char> &a, pair<pii, char> &b) {
        if (a.x.y == b.x.y) return a.x.x < b.x.x;
        return a.x.y < b.x.y;
    });
    for (auto &e : v) cout << e.y;
    cout << endl;
    return 0;
}