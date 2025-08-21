#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

vector<pii> v;
int dp[1010][10101];
int main() {
    fastio;
    int N, K; cin >> N >> K;
    v.push_back({42, 42});
    for (int i = 0; i < K; i++) {
        int I, T; cin >> I >> T;
        v.push_back({I, T});
    }

    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            if (v[i].second > j) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].second] + v[i].first);
        }
    }
    cout << dp[K][N] << endl;
    return 0;
}