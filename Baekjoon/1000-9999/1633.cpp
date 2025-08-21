#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll ans = 0;
vector<pii> v;
int main() {
    fastio;
    
    int a, b;
    while (cin >> a >> b) {
        v.push_back({a, b});    
    }

    sort(all(v), [&](pii &a, pii &b) {
        return a.x > b.x;
    });
    for (int i = 0; i < 15; i++) {
        ans += v[i].x;
    }
    sort(v.begin() + 15, v.end(), [&](pii &a, pii &b) {
        return a.y > b.y;
    });
    for (int i = 0; i < 15; i++) {
        ans += v[i+15].y;
    }

    ll tmp = 0;
    sort(all(v), [&](pii &a, pii &b) {
        return a.y > b.y;
    });
    
    for (int i = 0; i < 15; i++) {
        tmp += v[i].y;
    }
    sort(v.begin() + 15, v.end(), [&](pii &a, pii &b) {
        return a.x > b.x;
    });

    for (int i = 0; i < 15; i++) {
        tmp += v[i+15].x;
    }

    cout << max(ans, tmp) << endl;
    return 0;
}