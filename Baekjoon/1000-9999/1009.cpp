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
    while (T--) {
        int a, b; cin >> a >> b;
        a = (a - 1) % 10 + 1; b--;
        if (a == 1 || a == 5 || a == 6 || a == 10) cout << a << endl;
        if (a == 2) cout << "2486"[b % 4] << endl;
        if (a == 3) cout << "3971"[b % 4] << endl;
        if (a == 4) cout << "46"[b % 2] << endl;
        if (a == 7) cout << "7931"[b % 4] << endl;
        if (a == 8) cout << "8426"[b % 4] << endl;
        if (a == 9) cout << "91"[b % 2] << endl;
    }
    return 0;
}