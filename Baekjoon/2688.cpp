#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

ll dp[65][10];
int T, N;
int main() {
    fastio;
    cin >> T;
    for (int i = 0; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i < 65; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    while (T--) {
        cin >> N;
        ll ans = 0;
        for (int i = 0; i < 10; i++) ans += dp[N][i];
        cout << ans << endl;
    }
    return 0;
}