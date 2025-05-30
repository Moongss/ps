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

vector<ll> f;

int main() {
    fastio;

    f.push_back(1);
    f.push_back(1);
    for (int i = 2;;i++) {
        f.push_back(f[i-1] + f[i-2]);
        if (f.back() > 1e9) break;
    }
    reverse(all(f));

    int T; cin >> T;
    while (T--) {
        ll N; cin >> N;
        vector<ll> ret;
        for (auto &e : f) if (N >= e) N -= e, ret.push_back(e);

        reverse(all(ret));
        for (auto &x : ret) cout << x << " "; cout << endl;
    }
    
    return 0;
}