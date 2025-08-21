#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<tuple<string, int, int>> v;

int main() {
    fastio;

    string a, b, c; cin >> a >> b >> c;
    v = {
        {"black", 0, 1},
        {"brown", 1, 10},
        {"red", 2, 100},
        {"orange", 3, 1000},
        {"yellow", 4, 10000},
        {"green", 5, 100000},
        {"blue", 6, 1000000},
        {"violet", 7, 10000000},
        {"grey", 8, 100000000},
        {"white", 9, 1000000000}
    };
    
    ll ans = 0;
    for (int i = 0; i < 3; i++) {
        for (auto [s, n, m] : v) {
            if (i == 0 && a == s) ans += n * 10;
            if (i == 1 && b == s) ans += n;
            if (i == 2 && c == s) ans *= m;
        }
    }
    cout << ans << endl;
    return 0;
}