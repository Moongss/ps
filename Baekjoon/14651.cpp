#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    
    int N; cin >> N;
    int dp[3] = {0, 1, 1};

    for (int i = 1; i < N; i++) {
        int tmp[3] = {0, 0, 0};
        tmp[0] = (dp[0] + dp[1] + dp[2]) % 1000000009;
        tmp[1] = (dp[0] + dp[1] + dp[2]) % 1000000009;
        tmp[2] = (dp[0] + dp[1] + dp[2]) % 1000000009;

        for (int j = 0; j < 3; j++)
            dp[j] = tmp[j];
    }
    cout << dp[0] << endl;
    return 0;
}