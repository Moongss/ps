#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N, K;
int pre[11][2001];
int dp[11][2001];
vector<int> book[11];

int main() {
    fastio;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int C, G; cin >> C >> G;
        book[G].push_back(C);
    }

    for (int i = 1; i <= 10; i++) {
        sort(book[i].begin(), book[i].end(), greater<int>());
        for (int j = 1; j <= book[i].size(); j++) {
            pre[i][j] = pre[i][j - 1] + book[i][j - 1];
        }
        for (int j = 1; j <= book[i].size(); j++) {
            pre[i][j] += (j * (j - 1));
        }
    }

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= K; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + pre[i][j - k]);
            }
        }
    }
    cout << dp[10][K] << endl;
    return 0;
}