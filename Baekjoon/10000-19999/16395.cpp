#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, k;
int dp[31][31];

int main() {
    fastio;
    
    for (int i = 1; i <= 30; i++) {
        dp[i][1] = dp[i][i] = 1;
        for (int j = 2; j < i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    cin >> n >> k;
    cout << dp[n][k] << endl;
    return 0;
}