#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

ll N, K;
ll P = 10007;
int dp[1001][1001] = {0, };

int main() {
    fastio;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {dp[i][j] = 1; continue;}
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % P;
        }
    }

    cout << dp[N][K] << endl;
    return 0;
}