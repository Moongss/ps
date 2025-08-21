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
    
    int N; cin >>N;
    vector<int>v; v.resize(N);
    for (auto &i : v) cin >> i;

    int cnt = 0;
    while (true) {
        bool f = false;
        for (int i = 0; i < N; i++) if (v[i]) {
            f = true; break;
        }
        if (!f) break;

        bool f2 = true;
        for (auto &i : v) if (i % 2 != 0) {
            f2 = false; break;
        }

        if (f2) {
            for (auto &i : v) i /= 2;
            cnt++;
        } else {
            for (auto &i : v) if (i % 2) {
                i--; cnt++;
            }
        }
    }
    cout << cnt<< endl;
    return 0;
}