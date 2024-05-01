#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, m;
ll dp[1001][1001];

int main() {
    fastio;
    cin >> n >> m;

    dp[0][0] = 1;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007;
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}