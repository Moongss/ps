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
    
    int t; 
    while (cin >> t && t) {
        vector<int> v; v.resize(t);
        for (auto &i : v) cin >> i;
        sort(all(v));

        bool f = false;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] - v[i - 1] > 200) {
                f = true;
                break;
            }
        }
        if (1422 - v.back() > 100) f = true;
        cout << (f ? "IMPOSSIBLE" : "POSSIBLE") << endl;
    }
    return 0;
}