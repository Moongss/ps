#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define MOD 1000000003

ll dp[1001][1001];
int N, K;

int main() {
    fastio;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        dp[i][1] = i;
        for (int j = 2; j <= K; j++) {
            if (j > i / 2) break;
            dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
        }
    }

    cout << dp[N][K] << endl;
    return 0;
}