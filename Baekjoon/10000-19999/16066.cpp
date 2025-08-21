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

    while (n--) {
        string a, b; cin >> a >> b;
        ll c = 0, d = 0;

        for (auto &i : a) {
            if (i == '.') continue;
            c = c * 10 + i - '0';
        }
        for (auto &i : b) {
            if (i == '.') continue;
            d = d * 10 + i - '0';
        }
        
        ll gcd = __gcd(c, d);
        c /= gcd; d /= gcd;

        if (c == 1 && d == 1) {
            cout << "2 2" << endl;
            continue;
        }

        bool f = false;
        for (int i = 2; i * i <= c; i++) {
            if (c % i == 0) {
                f = true; break;
            }
        }
        for (int i = 2; i * i <= d; i++) {
            if (d % i == 0) {
                f = true; break;
            }
        }

        if (f || c == 1 || d == 1) {
            cout << "impossible" << endl;
        } else {
            cout << c << " " << d << endl;
        }
    }   
    return 0;
}