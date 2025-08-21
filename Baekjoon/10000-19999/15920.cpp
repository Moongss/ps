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

int main() {
    fastio;
    int n; cin >> n;
    string s; cin >> s;

    int cnt = 0;
    bool f = false;
    bool f2 = false;
    for (auto &c : s) {
        if (c == 'P') {
            f = !f;
            if (cnt == 1) f2 = true;
        }
        if (c == 'W') cnt++;
        if (cnt == 2) break;
    }
    if (cnt >= 2) {
        if (f2) cout << 6 << endl;
        else if (f) cout << 1 << endl;
        else cout << 5 << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}