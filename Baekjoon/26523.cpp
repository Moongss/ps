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
    
    for (int t = 0; t < 10; t++) {
        int cnt = 0;
        for (int i = 0; i < 5000; i++) {
            double d; cin >> d;
            int tmp = d * 10000;
            if (0 <= tmp && tmp <= 10000) cnt++;
        }

        if (cnt == 2500) cout << "A" << endl;
        else cout << "B" << endl;
    }
    return 0;
}