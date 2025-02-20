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

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
vector<pll> v;

pll tmp;
int main() {
    fastio;

    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    
    sort(all(v));
    ll ans = 0;
    tmp = v[0];
    for (auto [s, e] : v) {
        if (tmp.y < s) {
            ans += tmp.y - tmp.x;
            tmp = {s, e};
        } else {
            tmp.y = max(tmp.y, e);
        }
    }
    ans += tmp.y - tmp.x;

    cout << ans << endl;
    return 0;
}