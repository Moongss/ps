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
    
    int ret = 0;
    for (int i = 0;i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c; cin >> c;
            if (!(c&32) && !((i+j)&1)) ret++;
        }
    }
    cout << ret << endl;
    return 0;
}