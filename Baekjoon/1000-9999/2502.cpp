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

int dp[31][2];
int main() {
    fastio;
    
    int D, K; cin >> D >> K;

    dp[1][0] = dp[2][1] = 1;
    for (int i = 3; i <= D; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }

    for (int i = 1; i < K; i++) {
        if ((K - dp[D][0] * i) % dp[D][1] == 0) {
            cout << i << endl << (K - dp[D][0] * i) / dp[D][1] << endl;
            return 0;
        } 
    }
    return 0;
}