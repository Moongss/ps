#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    
    vector<double> v; 
    for (int i = 0; i < 10; i++) {
        double d; cin >> d; 
        cout << (int)(d * 100) << endl;
        v.push_back(d);
    }

    sort(all(v)); reverse(all(v));

    ld ans = 1.0f;
    ll tmp = 1;
    for (int i = 0; i < 9; i++) {
        ans *= v[i];
        // cout << ans << endl;
        tmp *= (i+1);
    }
    ans /= tmp;
    cout << fixed << setprecision(6) << ans * 1000000000<< endl;
    return 0;
}