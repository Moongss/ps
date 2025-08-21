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

map<ll, int> s;
int n, m;
int main() {
    fastio;
    
    cin >> n >> m;
    while (n--) {
        int k; cin >> k;
        for (int i = 0; i < k; i++) {
            ll x; cin>> x; s[x]++;
        }
    }

    int ret = 0;
    for (auto [k, v]: s) {
        if (v >= m) ret++;
    }
    cout << ret << endl;

    return 0;
}