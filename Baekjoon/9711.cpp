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

ll dp[10001];
int main() {
    fastio;
    
    int N; cin >> N;

    for (int i = 1; i <= N; i++) {
        ll P, Q; cin >> P >> Q;
        dp[1] = dp[2] = 1;
        for (int j = 3; j <= P; j++) {
            dp[j] = dp[j - 1] + dp[j - 2];
            dp[j] %= Q;
        }
        cout << "Case #" << i << ": " << dp[P] % Q << endl;
    }
    return 0;
}