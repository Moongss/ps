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

int main() {
    fastio;
    
    ll ret = 0;
    int n; cin >> n; vector<int> v(n); for (auto& i : v) cin >> i;
    sort(all(v)); reverse(all(v));

    for (int i = 0; i < n; i++) {
        ret = max(ret, (ll)v[i] * (i + 1));
    }
    cout << ret << endl;
    return 0;
}