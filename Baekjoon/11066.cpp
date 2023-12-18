#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int T, N;
int dp[501][501];
int sum[501];

int main() {
    fastio;
    
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> v;
        for (int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            v.push_back(tmp);
            sum[i] = (i == 0 ? tmp : sum[i - 1] + tmp);
        }

        for (int i = 0; i < N; i++) dp[i][i] = v[i];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - i; j++) {
                int s = j, e = j + i;
                if (s == e) continue;
                dp[s][e] = INT_MAX;
                for (int k = s; k < e; k++) {
                    dp[s][e] = min(dp[s][e], dp[s][k] + dp[k + 1][e] + sum[e] - (s == 0 ? 0 : sum[s - 1]));
                }
            }
        }
        cout << dp[0][N - 1] - sum[N - 1] << endl;
    }
    return 0;
}