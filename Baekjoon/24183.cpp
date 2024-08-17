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

    double C4 = 229 * 324;
    double A3 = 297 * 420;
    double A4 = 210 * 297;
    
    ll A, B, C; cin >> A >> B >> C;
    double ans = A * C4 * 2 + B * A3 * 2 + C * A4;
    cout << fixed << setprecision(6) << ans * 1e-6 << endl;

    return 0;
}