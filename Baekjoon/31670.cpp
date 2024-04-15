#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll dp[100001][2];
int main() {
    fastio;
    
    int N; cin >> N; 
    for (int i = 1; i <= N; i++) {
        ll x; cin >> x;
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + x;
    }
    cout << min(dp[N][0], dp[N][1]) << endl;
    return 0;
}