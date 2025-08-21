#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int dp[101][101][101];

int main() {
    fastio;
    string a, b, c; cin >> a >> b >> c;
    a = '0' + a;
    b = '0' + b;
    c = '0' + c;

    for (int i = 1; i < a.length(); i++) {
        for (int j = 1; j < b.length(); j++) {
            for (int k = 1; k < c.length(); k++) {
                if (a[i] == b[j] && a[i] == c[k])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
            }
        }
    }

    cout << dp[a.length() - 1][b.length() - 1][c.length() - 1] << endl;
    return 0;
}