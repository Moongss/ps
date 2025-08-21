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
    
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";

        int N; cin >> N;
        if (N == 1) {
            ll c1, c2; cin >> c1 >> c2;
            cout << fixed << setprecision(9) << (double)(c2 - c1) / c1 << endl;
        } else {
            ll c1, c2, c3;
            cin >> c1 >> c2 >> c3;

            double a = c1;
            double b = 2 * c1 - c2;
            double c = c1 - c2 - c3;

            double r1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
            double r2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

            if (r1 > -1 && r1 < 1) cout << fixed << setprecision(9) << r1 << endl;
            else cout << fixed << setprecision(9) << r2 << endl;
        }
    }
    return 0;
}