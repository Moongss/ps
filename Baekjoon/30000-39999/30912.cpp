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
vector<pll> rot[9];

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i< N; i++) {
        ll x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    pll hyuk; cin >> hyuk.x >> hyuk.y;

    for (auto [a, b] : v) {
        ll x = a - hyuk.x;
        ll y = b - hyuk.y;

        if (x == 0 && y > 0) rot[6].push_back({x, y});
        else if (x < 0 && y > 0) rot[7].push_back({x, y});
        else if (x < 0 && y == 0) rot[0].push_back({x, y});
        else if (x < 0 && y < 0) rot[1].push_back({x, y});
        else if (x == 0 && y < 0) rot[2].push_back({x, y});
        else if (x > 0 && y < 0) rot[3].push_back({x, y});
        else if (x > 0 && y == 0) rot[4].push_back({x, y});
        else if (x > 0 && y > 0) rot[5].push_back({x, y});
    }

    for (int i = 0; i < 8; i++) {
        sort(all(rot[i]), [&](pll a, pll b) {
            if (a.x == 0) return abs(a.y) < abs(b.y);
            if (a.y == 0) return abs(a.x) < abs(b.x);
            if (a.y * b.x == a.x * b.y) {
                if (a.x != b.x) return abs(a.x) < abs(b.x);
                if (a.y != b.y) return abs(a.y) < abs(b.y);
            }
            return a.y * b.x < a.x * b.y;
        });
    }

    for (int i = 0; i < 8; i++) {
        for (auto [x, y] : rot[i]) {
            cout << x + hyuk.x << " " << y + hyuk.y << endl;
        }
    }

    return 0;
}