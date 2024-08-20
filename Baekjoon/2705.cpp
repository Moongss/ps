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

int N, dp[1001];
int T;
int main() {
    fastio;
    
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        for (int j = 0; j * 2 <= i; j++) {
            dp[i] += dp[j];
        }
    }

    cin >> T;
    while (T--) {
        int x; cin >> x; cout << dp[x] << endl;
    }
    return 0;
}